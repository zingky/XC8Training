using System;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;
using System.Threading;

namespace UART_Terminal
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private bool Uart_Connect()
        {
            try
            {
                if (Uart.IsOpen) Uart.Close();
                Uart.PortName = cb_uartport.Text;
                Uart.BaudRate = int.Parse(cb_baudrate.Text);
                Uart.Open();
                rtb_receive.Text = "Connect: " + cb_uartport.Text + " ,baud= " + cb_baudrate.Text + "\r\n";
                return true;
            }
            catch
            {
                rtb_receive.Text = "Connect: failed";
            }
            return false;
        }

        private void Uart_Disconnect()
        {
            if (Uart.IsOpen) Uart.Close();
            rtb_receive.Text = "Disconnect";
        }
        private void cb_uartport_MouseClick(object sender, MouseEventArgs e)
        {
            string[] ports = SerialPort.GetPortNames();
            cb_uartport.Items.Clear();
            if (ports != null)
            {
                foreach (string port in ports)
                {
                    cb_uartport.Items.Add(port);
                }
            }
            else cb_uartport.Items.Add("No COM");
        }

        private void bt_connect_Click(object sender, EventArgs e)
        {
            if(bt_connect.Text=="Connect")
            {
                if(Uart_Connect())
                {
                    Task_Init();
                    bt_send.Enabled = true;
                    bt_connect.Text = "Disconnect";
                }
            }
            else
            {
                Uart_Disconnect();
                Task_DeInit();
                bt_send.Enabled = false;
                bt_connect.Text = "Connect";
            }
        }

        private void bt_send_Click(object sender, EventArgs e)
        {
            Uart.Write(tb_send.Text);
        }
        private struct uart_buffer_t
        {
            public volatile int Prv_Len;
            public volatile int Pre_Len;
            public volatile byte[] Data;
        }

        uart_buffer_t UBuf;

        private void Uart_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            int i;
            int byte2read = Uart.BytesToRead;// Đọc số byte data nhận được trong buffer
            byte[] temp = new byte[byte2read];// Tạo mảng lưu data với kích thước bằng số byte cần đọc
            Uart.Read(temp, 0, byte2read);// Đọc và lưu dữ liệu
            for (i = 0; i < byte2read; i++)// Chép dữ liệu vào buffer người dùng để xử lý
            {
                UBuf.Data[UBuf.Pre_Len] = temp[i];
                UBuf.Pre_Len++;
            }
            // RX Interrupt - Để đây, tính sau
        }

        Thread Thread_Task;
        Tick_Timer Tick;
        Tick_Timer.tick_timer_t t;

        private void Task_Init()
        {
            Tick = new Tick_Timer();
            Tick.Init();
            Thread_Task = new Thread(() => Task_Service());
            Thread_Task.Start();
        }

        private void Task_DeInit()
        {
            Tick.DeInit();
            if (Thread_Task.IsAlive) Thread_Task.Abort();
        }

        private void Task_Service()
        {
            UBuf.Data = new byte[4096];// tạo buffer người dùng với kích thước 4Kbyte
            UBuf.Pre_Len = UBuf.Prv_Len = 0;// khởi tạo giá trị độ dài dữ liệu trong buffer
            Tick.Reset(ref t);// reset timer nhận dữ liệu
            while (true)
            {
                Control.CheckForIllegalCrossThreadCalls = false;
                if (UBuf.Prv_Len != UBuf.Pre_Len)// Nếu độ dài buffer ở chu kỳ trước khác độ dài buffer chu kỳ sau
                {
                    Tick.Reset(ref t);// reset tick
                    UBuf.Prv_Len = UBuf.Pre_Len;// cập nhật lại độ dài buffer
                }
                else if (UBuf.Pre_Len > 0)// Nếu độ dài buffer >0 - có dữ liệu trong buffer
                {
                    if (Tick.Is_Over(ref t, 100))// Nếu sau 100ms mà độ dài buffer chu kỳ trước và sau không đổi 
                                                 //có nghĩa là dữ liệu truyền đã kết thúc (tuỳ chỉnh giá trị)
                    {
                        string s = null;// Dữ liệu gửi là dạng string, ta tạo 1 biến để lưu
                        for (int i = 0; i < UBuf.Pre_Len; i++)// Convert từng byte nhận được sang string
                        {
                            byte[] c = new byte[1];
                            c[0] = UBuf.Data[i];
                            s += ASCIIEncoding.UTF8.GetString(c, 0, 1);
                        }
                        UBuf.Pre_Len = UBuf.Prv_Len = 0;// Xoá độ dài buffer - Chú ý xoá ngay khi xử lý xong
                        rtb_receive.AppendText(s);// In chuỗi nhận được ra text box
                    }
                }
            }
        }

    }
}
