using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Media;
using System.Net;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ToolBar;

namespace TrainwareShappire
{
    public partial class TrainwareShappire : Form
    {
        String ipESP;
        int portESP;
        String SenttoESP32;

        public TrainwareShappire()
        {
            InitializeComponent();
            Thread thdUDPServer = new Thread(new ThreadStart(serverThread));
            thdUDPServer.Start();
        }

        private void SetIpPortESP32_Click(object sender, EventArgs e)
        {
            ipESP = ipESP32.Text;
            portESP = Convert.ToInt32(portESP32.Text);
        }

        SoundPlayer simpleSound = new SoundPlayer(@"D:\TrainWare\Code\2 PLATFORM\Visual Studio\TrainWare - Shappire\TrainwareShappire\assets\alarm_.wav");

        private void playSound()
        {
            simpleSound.PlayLooping();
        }

        private void stopSound()
        {
            simpleSound.Stop();
        }

        String[] buffer;
        int POT = 0;
        int SUHU = 0;
        int JARAK = 0;
        int LED3 = 0;
        int LED4 = 0;

        int push_LED4 = 0;
        int push_LED3 = 0;
        int push_servo = 0;

        public void serverThread() //SERVER
        {
            UdpClient udpClient = new UdpClient(8080);
            while (true)
            {
                IPEndPoint RemoteIpEndPoint = new IPEndPoint(IPAddress.Any, 8080);
                Byte[] receiveBytes = udpClient.Receive(ref RemoteIpEndPoint);
                string returnData = Encoding.ASCII.GetString(receiveBytes);

                this.Invoke(new MethodInvoker(delegate ()
                {
                    listbox_rec.Items.Add(RemoteIpEndPoint.Address.ToString() + " : " + returnData.ToString());
                    listbox_rec.SelectedIndex = listbox_rec.Items.Count - 1;
                    listbox_rec.SelectedIndex = -1;
                    StatusRec.Text = returnData.ToString();
                    buffer = returnData.Split('#');
                    POT = Convert.ToInt32(buffer[0]);
                    SUHU = Convert.ToInt32(buffer[1]);
                    JARAK = Convert.ToInt32(buffer[2]);
                    LED3 = Convert.ToInt32(buffer[3]);
                    LED4 = Convert.ToInt32(buffer[4]);

                    if(POT >= 80)
                    {
                        alertIMG(true);
                        CirBarPOT.ProgressColor = System.Drawing.Color.FromArgb(((int)(((byte)(243)))), ((int)(((byte)(181)))), ((int)(((byte)(25)))));
                    }
                    else
                    {
                        alertIMG(false);
                        CirBarPOT.ProgressColor = System.Drawing.Color.FromArgb(((int)(((byte)(9)))), ((int)(((byte)(106)))), ((int)(((byte)(175)))));
                    }


                    CirBarPOT.Text = buffer[0] + " %";
                    CirBarPOT.Value = POT;
                    suhuDHT.Text = SUHU.ToString() + " °C";
                    distUS.Text = JARAK.ToString() + " CM";

                    if (LED3 == 1)
                    {
                        btnLED3.BackColor = Color.Green;
                        btnLED3.Text = "LED 3 ON"; 
                    }
                    else
                    {
                        btnLED3.BackColor = Color.Red;
                        btnLED3.Text = "LED 3 OFF";
                    }

                    if (LED4 == 1)
                    {
                        btnLED4.BackColor = Color.Green;
                        btnLED4.Text = "LED 4 ON";
                    }
                    else
                    {
                        btnLED4.BackColor = Color.Red;
                        btnLED4.Text = "LED 4 OFF";
                    }

                }));
            }
        }

        private void TrainwareShappire_Load(object sender, EventArgs e)
        {
            string hostName = Dns.GetHostName();
            string myIP = Dns.GetHostByName(hostName).AddressList[0].ToString();
            ipPC.Text = myIP;
        }

        private void minCTRL_Click(object sender, EventArgs e)
        {
            WindowState = FormWindowState.Minimized;
        }

        private void closeCTRL_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        public const int WM_NCLBUTTONDOWN = 0xA1;
        public const int HTCAPTION = 0x2;
        [DllImport("User32.dll")]
        public static extern bool ReleaseCapture();
        [DllImport("User32.dll")]
        public static extern int SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);

        private void OnMouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                ReleaseCapture();
                SendMessage(Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
            }
        }

        private const int dp = 0x00020000;
        protected override CreateParams CreateParams
        {
            get
            {
                CreateParams cp = base.CreateParams;
                cp.ClassStyle |= dp;
                return cp;
            }
        }

        private delegate void LampuMatiDelegate(bool item);
        private void LampuMati(bool item)
        {
            if (InvokeRequired)
                lightoff.Invoke(new LampuMatiDelegate(LampuMati), item);
            else
            {
                lightoff.Visible = item;
            }
        }

        private delegate void LampuHidupDelegate(bool item);
        private void LampuHidup(bool item)
        {
            if (InvokeRequired)
                lighton.Invoke(new LampuHidupDelegate(LampuHidup), item);
            else
            {
                lighton.Visible = item;
            }
        }

        private void alertIMG(bool item)
        {
            if (item == true)
            {
                LampuHidup(true);
                LampuMati(false);
            }
            else
            {
                LampuHidup(false);
                LampuMati(true);
            }
        }

        private void btnLED4_Click(object sender, EventArgs e)
        {
            if (LED4 == 1)
            {
                push_LED4 = 0;
            }
            else
            {
                push_LED4 = 1;
            }

            SenttoESP32 = push_LED3.ToString() + "," + push_LED4.ToString() + "," + push_servo.ToString();

            byte[] data = Encoding.ASCII.GetBytes(SenttoESP32);
            try
            {
                using (var client = new UdpClient())
                {
                    IPEndPoint ep = new IPEndPoint(IPAddress.Parse(ipESP), portESP);
                    client.Connect(ep);
                    client.Send(data, data.Length);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
        }

        private void btnLED3_Click(object sender, EventArgs e)
        {
            if (LED3 == 1)
            {
                push_LED3 = 0;
            }
            else
            {
                push_LED3 = 1;
            }

            SenttoESP32 = push_LED3.ToString() + "," + push_LED4.ToString() + "," + push_servo.ToString();

            byte[] data = Encoding.ASCII.GetBytes(SenttoESP32);
            try
            {
                using (var client = new UdpClient())
                {
                    IPEndPoint ep = new IPEndPoint(IPAddress.Parse(ipESP), portESP);
                    client.Connect(ep);
                    client.Send(data, data.Length);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
        }

        private void cp_ipPC_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(ipPC.Text);
        }

        private void btnSERVO_Click(object sender, EventArgs e)
        {
            push_servo = Convert.ToInt32(degreeServo.Text);
            SenttoESP32 = push_LED3.ToString() + "," + push_LED4.ToString() + "," + push_servo.ToString();

            byte[] data = Encoding.ASCII.GetBytes(SenttoESP32);
            try
            {
                using (var client = new UdpClient())
                {
                    IPEndPoint ep = new IPEndPoint(IPAddress.Parse(ipESP), portESP);
                    client.Connect(ep);
                    client.Send(data, data.Length);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
        }
    }
}
