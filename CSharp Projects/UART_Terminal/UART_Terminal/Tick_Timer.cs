using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Diagnostics;

namespace UART_Terminal
{
    class Tick_Timer
    {
        private static volatile UInt32 tickcount;
        private Stopwatch SYSTMR;
        private Thread Thread_Tick;

        public struct tick_timer_t
        {
            public UInt32 Start;
            public UInt32 Stop;
            public bool Timeout;
        }

        public void Init()
        {
            tickcount = 0;
            SYSTMR = new Stopwatch();
            Thread_Tick = new Thread(() => Tick_Service());
            Thread_Tick.Start();
        }

        public void DeInit()
        {
            SYSTMR.Stop();
            if (Thread_Tick.IsAlive) Thread_Tick.Abort();
        }

        public void Reset(ref tick_timer_t tick)
        {
            tick.Timeout = true;
        }

        private void Tick_Service()
        {
            while(true)
            {
                SYSTMR.Restart();
                while (SYSTMR.ElapsedMilliseconds == 0) ;
                tickcount++;
            }
        }

        public bool Is_Over(ref tick_timer_t tick, UInt32 ms)
        {
            UInt32 real_tick = tickcount;
            if (tick.Timeout)
            {
                tick.Start = real_tick;
                tick.Stop = real_tick + ms;
            }
            if (tick.Stop > tick.Start) tick.Timeout = (tick.Stop < real_tick);
            else tick.Timeout = ((tick.Stop < real_tick) && (real_tick < tick.Start));
            return tick.Timeout;
        }

    }
}
