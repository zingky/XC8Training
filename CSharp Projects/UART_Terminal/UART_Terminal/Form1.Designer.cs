namespace UART_Terminal
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.cb_uartport = new System.Windows.Forms.ComboBox();
            this.bt_connect = new System.Windows.Forms.Button();
            this.rtb_receive = new System.Windows.Forms.RichTextBox();
            this.cb_baudrate = new System.Windows.Forms.ComboBox();
            this.bt_send = new System.Windows.Forms.Button();
            this.tb_send = new System.Windows.Forms.TextBox();
            this.Uart = new System.IO.Ports.SerialPort(this.components);
            this.SuspendLayout();
            // 
            // cb_uartport
            // 
            this.cb_uartport.FormattingEnabled = true;
            this.cb_uartport.Location = new System.Drawing.Point(12, 12);
            this.cb_uartport.Name = "cb_uartport";
            this.cb_uartport.Size = new System.Drawing.Size(121, 21);
            this.cb_uartport.TabIndex = 0;
            this.cb_uartport.Text = "No COM";
            this.cb_uartport.MouseClick += new System.Windows.Forms.MouseEventHandler(this.cb_uartport_MouseClick);
            // 
            // bt_connect
            // 
            this.bt_connect.Location = new System.Drawing.Point(139, 12);
            this.bt_connect.Name = "bt_connect";
            this.bt_connect.Size = new System.Drawing.Size(83, 50);
            this.bt_connect.TabIndex = 1;
            this.bt_connect.Text = "Connect";
            this.bt_connect.UseVisualStyleBackColor = true;
            this.bt_connect.Click += new System.EventHandler(this.bt_connect_Click);
            // 
            // rtb_receive
            // 
            this.rtb_receive.Location = new System.Drawing.Point(12, 68);
            this.rtb_receive.Name = "rtb_receive";
            this.rtb_receive.Size = new System.Drawing.Size(210, 182);
            this.rtb_receive.TabIndex = 2;
            this.rtb_receive.Text = "";
            // 
            // cb_baudrate
            // 
            this.cb_baudrate.FormattingEnabled = true;
            this.cb_baudrate.Items.AddRange(new object[] {
            "9600",
            "19200",
            "57600",
            "115200"});
            this.cb_baudrate.Location = new System.Drawing.Point(12, 41);
            this.cb_baudrate.Name = "cb_baudrate";
            this.cb_baudrate.Size = new System.Drawing.Size(121, 21);
            this.cb_baudrate.TabIndex = 3;
            this.cb_baudrate.Text = "9600";
            // 
            // bt_send
            // 
            this.bt_send.Enabled = false;
            this.bt_send.Location = new System.Drawing.Point(12, 282);
            this.bt_send.Name = "bt_send";
            this.bt_send.Size = new System.Drawing.Size(210, 27);
            this.bt_send.TabIndex = 1;
            this.bt_send.Text = "Send";
            this.bt_send.UseVisualStyleBackColor = true;
            this.bt_send.Click += new System.EventHandler(this.bt_send_Click);
            // 
            // tb_send
            // 
            this.tb_send.Location = new System.Drawing.Point(12, 256);
            this.tb_send.Name = "tb_send";
            this.tb_send.Size = new System.Drawing.Size(210, 20);
            this.tb_send.TabIndex = 4;
            // 
            // Uart
            // 
            this.Uart.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.Uart_DataReceived);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(234, 323);
            this.Controls.Add(this.tb_send);
            this.Controls.Add(this.cb_baudrate);
            this.Controls.Add(this.rtb_receive);
            this.Controls.Add(this.bt_send);
            this.Controls.Add(this.bt_connect);
            this.Controls.Add(this.cb_uartport);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "UART";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox cb_uartport;
        private System.Windows.Forms.Button bt_connect;
        private System.Windows.Forms.RichTextBox rtb_receive;
        private System.Windows.Forms.ComboBox cb_baudrate;
        private System.Windows.Forms.Button bt_send;
        private System.Windows.Forms.TextBox tb_send;
        private System.IO.Ports.SerialPort Uart;
    }
}

