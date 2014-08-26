using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Xna.Framework.Input;
using System.Threading;

namespace LineDebugger
{
    public delegate void ValueChangeHandler(int val);

    class Controller
    {
        private const int TURN_MAX = 700;
        private const int THROTTLE_MAX = 500;
        private const int THROTTLE_STOP = 500;

        public event ValueChangeHandler DirectionChange,ThrottleChange;

        public Controller()
        {
        }

        public void Start()
        {
            Thread controlMonitor = new Thread(new ThreadStart(MonitorControl));
            controlMonitor.Name = "Controller Monitor";
            controlMonitor.IsBackground = true;
            controlMonitor.Start();
        }

        private void MonitorControl()
        {
            GamePadState gpState = GamePad.GetState(Microsoft.Xna.Framework.PlayerIndex.One);
            GamePadState gppState = gpState;

            while (true)
            {

                gppState = gpState;
                gpState = GamePad.GetState(Microsoft.Xna.Framework.PlayerIndex.One);

                // Check the direction
                if (gpState.ThumbSticks.Left.X != gppState.ThumbSticks.Left.X)
                {
                    float dir = gpState.ThumbSticks.Left.X;

                    dir = dir * TURN_MAX/2 + TURN_MAX/2;

                    if(DirectionChange != null)
                        DirectionChange((int)dir);
                }

                // check the throttle
                if (gpState.Triggers.Right != gppState.Triggers.Right)
                {
                    float throttle = gpState.Triggers.Right;

                    throttle = (int)(throttle * THROTTLE_MAX) + THROTTLE_STOP;
                  



                    if (ThrottleChange != null)
                        ThrottleChange((int)throttle);
                }
                if (gpState.Triggers.Left != gppState.Triggers.Left)
                {
                    float throttle = gpState.Triggers.Left;

                    throttle = THROTTLE_STOP - (int)(throttle * THROTTLE_MAX);



                    if (ThrottleChange != null)
                        ThrottleChange((int)throttle);
                }

                if (gpState.Buttons.X != gppState.Buttons.X)
                {
                    DirectionChange(TURN_MAX / 2);
                }
                if (gpState.Buttons.A != gppState.Buttons.A)
                {
                    ThrottleChange(THROTTLE_STOP);
                }

                System.Threading.Thread.Sleep(10);
            }
        }
    }
}
