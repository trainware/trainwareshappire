namespace TrainwareShappire
{
    partial class TrainwareShappire
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
            this.ipESP32 = new System.Windows.Forms.TextBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.minCTRL = new System.Windows.Forms.Button();
            this.closeCTRL = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.cp_ipPC = new System.Windows.Forms.Button();
            this.label15 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.ipPC = new System.Windows.Forms.Label();
            this.lighton = new System.Windows.Forms.PictureBox();
            this.SetIpPortESP32 = new System.Windows.Forms.Button();
            this.portESP32 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.lightoff = new System.Windows.Forms.PictureBox();
            this.panel3 = new System.Windows.Forms.Panel();
            this.StatusRec = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.btnSERVO = new System.Windows.Forms.Button();
            this.label13 = new System.Windows.Forms.Label();
            this.degreeServo = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.distUS = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.suhuDHT = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.btnLED3 = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.btnLED4 = new System.Windows.Forms.Button();
            this.CirBarPOT = new CircularProgressBar.CircularProgressBar();
            this.label5 = new System.Windows.Forms.Label();
            this.listbox_rec = new System.Windows.Forms.ListBox();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.lighton)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.lightoff)).BeginInit();
            this.panel3.SuspendLayout();
            this.SuspendLayout();
            // 
            // ipESP32
            // 
            this.ipESP32.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(30)))), ((int)(((byte)(56)))), ((int)(((byte)(82)))));
            this.ipESP32.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ipESP32.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ipESP32.ForeColor = System.Drawing.SystemColors.Window;
            this.ipESP32.Location = new System.Drawing.Point(10, 39);
            this.ipESP32.Margin = new System.Windows.Forms.Padding(8);
            this.ipESP32.Name = "ipESP32";
            this.ipESP32.Size = new System.Drawing.Size(192, 29);
            this.ipESP32.TabIndex = 0;
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(243)))), ((int)(((byte)(181)))), ((int)(((byte)(25)))));
            this.panel1.Controls.Add(this.minCTRL);
            this.panel1.Controls.Add(this.closeCTRL);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Margin = new System.Windows.Forms.Padding(2);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(960, 33);
            this.panel1.TabIndex = 1;
            this.panel1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.OnMouseDown);
            // 
            // minCTRL
            // 
            this.minCTRL.AutoSize = true;
            this.minCTRL.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(9)))), ((int)(((byte)(106)))), ((int)(((byte)(175)))));
            this.minCTRL.BackgroundImage = global::TrainwareShappire.Properties.Resources.minimize;
            this.minCTRL.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.minCTRL.Cursor = System.Windows.Forms.Cursors.Hand;
            this.minCTRL.FlatAppearance.BorderSize = 0;
            this.minCTRL.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.minCTRL.Font = new System.Drawing.Font("Segoe UI", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.minCTRL.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.minCTRL.Location = new System.Drawing.Point(900, 5);
            this.minCTRL.Margin = new System.Windows.Forms.Padding(4);
            this.minCTRL.Name = "minCTRL";
            this.minCTRL.Size = new System.Drawing.Size(24, 24);
            this.minCTRL.TabIndex = 7;
            this.minCTRL.UseVisualStyleBackColor = false;
            this.minCTRL.Click += new System.EventHandler(this.minCTRL_Click);
            // 
            // closeCTRL
            // 
            this.closeCTRL.AutoSize = true;
            this.closeCTRL.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(9)))), ((int)(((byte)(106)))), ((int)(((byte)(175)))));
            this.closeCTRL.BackgroundImage = global::TrainwareShappire.Properties.Resources.close;
            this.closeCTRL.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.closeCTRL.Cursor = System.Windows.Forms.Cursors.Hand;
            this.closeCTRL.FlatAppearance.BorderSize = 0;
            this.closeCTRL.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.closeCTRL.Font = new System.Drawing.Font("Segoe UI", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.closeCTRL.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.closeCTRL.Location = new System.Drawing.Point(932, 5);
            this.closeCTRL.Margin = new System.Windows.Forms.Padding(4);
            this.closeCTRL.Name = "closeCTRL";
            this.closeCTRL.Size = new System.Drawing.Size(24, 24);
            this.closeCTRL.TabIndex = 5;
            this.closeCTRL.UseVisualStyleBackColor = false;
            this.closeCTRL.Click += new System.EventHandler(this.closeCTRL_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.Transparent;
            this.label3.Font = new System.Drawing.Font("Segoe UI", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(9)))), ((int)(((byte)(106)))), ((int)(((byte)(175)))));
            this.label3.Location = new System.Drawing.Point(6, 3);
            this.label3.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(291, 25);
            this.label3.TabIndex = 5;
            this.label3.Text = "UDP SendReceive by TrainWare";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.Control;
            this.label1.Location = new System.Drawing.Point(6, 14);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(71, 21);
            this.label1.TabIndex = 2;
            this.label1.Text = "IP ESP32";
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(44)))), ((int)(((byte)(77)))), ((int)(((byte)(111)))));
            this.panel2.Controls.Add(this.cp_ipPC);
            this.panel2.Controls.Add(this.label15);
            this.panel2.Controls.Add(this.label14);
            this.panel2.Controls.Add(this.ipPC);
            this.panel2.Controls.Add(this.lighton);
            this.panel2.Controls.Add(this.SetIpPortESP32);
            this.panel2.Controls.Add(this.portESP32);
            this.panel2.Controls.Add(this.label2);
            this.panel2.Controls.Add(this.lightoff);
            this.panel2.Controls.Add(this.ipESP32);
            this.panel2.Controls.Add(this.label1);
            this.panel2.Location = new System.Drawing.Point(0, 31);
            this.panel2.Margin = new System.Windows.Forms.Padding(2);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(214, 369);
            this.panel2.TabIndex = 2;
            // 
            // cp_ipPC
            // 
            this.cp_ipPC.AutoSize = true;
            this.cp_ipPC.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(9)))), ((int)(((byte)(106)))), ((int)(((byte)(175)))));
            this.cp_ipPC.BackgroundImage = global::TrainwareShappire.Properties.Resources._16216352;
            this.cp_ipPC.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.cp_ipPC.Cursor = System.Windows.Forms.Cursors.Hand;
            this.cp_ipPC.FlatAppearance.BorderSize = 0;
            this.cp_ipPC.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.cp_ipPC.Font = new System.Drawing.Font("Segoe UI", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cp_ipPC.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.cp_ipPC.Location = new System.Drawing.Point(162, 190);
            this.cp_ipPC.Margin = new System.Windows.Forms.Padding(2);
            this.cp_ipPC.Name = "cp_ipPC";
            this.cp_ipPC.Size = new System.Drawing.Size(40, 22);
            this.cp_ipPC.TabIndex = 42;
            this.cp_ipPC.UseVisualStyleBackColor = false;
            this.cp_ipPC.Click += new System.EventHandler(this.cp_ipPC_Click);
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.BackColor = System.Drawing.Color.Transparent;
            this.label15.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label15.ForeColor = System.Drawing.Color.White;
            this.label15.Location = new System.Drawing.Point(7, 215);
            this.label15.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(172, 15);
            this.label15.TabIndex = 41;
            this.label15.Text = "Masukkan IP PC ke Code ESP32";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.BackColor = System.Drawing.Color.Transparent;
            this.label14.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label14.ForeColor = System.Drawing.Color.White;
            this.label14.Location = new System.Drawing.Point(6, 168);
            this.label14.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(53, 21);
            this.label14.TabIndex = 40;
            this.label14.Text = "IP PC :";
            // 
            // ipPC
            // 
            this.ipPC.AutoSize = true;
            this.ipPC.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(243)))), ((int)(((byte)(181)))), ((int)(((byte)(25)))));
            this.ipPC.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ipPC.ForeColor = System.Drawing.Color.White;
            this.ipPC.Location = new System.Drawing.Point(10, 190);
            this.ipPC.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.ipPC.Name = "ipPC";
            this.ipPC.Size = new System.Drawing.Size(121, 21);
            this.ipPC.TabIndex = 39;
            this.ipPC.Text = "192.168.108.36";
            this.ipPC.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lighton
            // 
            this.lighton.Image = global::TrainwareShappire.Properties.Resources.alarmON;
            this.lighton.Location = new System.Drawing.Point(10, 256);
            this.lighton.Margin = new System.Windows.Forms.Padding(2);
            this.lighton.Name = "lighton";
            this.lighton.Size = new System.Drawing.Size(193, 102);
            this.lighton.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.lighton.TabIndex = 22;
            this.lighton.TabStop = false;
            // 
            // SetIpPortESP32
            // 
            this.SetIpPortESP32.AutoSize = true;
            this.SetIpPortESP32.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(9)))), ((int)(((byte)(106)))), ((int)(((byte)(175)))));
            this.SetIpPortESP32.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.SetIpPortESP32.Cursor = System.Windows.Forms.Cursors.Hand;
            this.SetIpPortESP32.FlatAppearance.BorderSize = 0;
            this.SetIpPortESP32.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.SetIpPortESP32.Font = new System.Drawing.Font("Segoe UI", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SetIpPortESP32.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.SetIpPortESP32.Location = new System.Drawing.Point(10, 134);
            this.SetIpPortESP32.Margin = new System.Windows.Forms.Padding(2);
            this.SetIpPortESP32.Name = "SetIpPortESP32";
            this.SetIpPortESP32.Size = new System.Drawing.Size(192, 32);
            this.SetIpPortESP32.TabIndex = 3;
            this.SetIpPortESP32.Text = "SET";
            this.SetIpPortESP32.UseVisualStyleBackColor = false;
            this.SetIpPortESP32.Click += new System.EventHandler(this.SetIpPortESP32_Click);
            // 
            // portESP32
            // 
            this.portESP32.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(30)))), ((int)(((byte)(56)))), ((int)(((byte)(82)))));
            this.portESP32.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.portESP32.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.portESP32.ForeColor = System.Drawing.SystemColors.Window;
            this.portESP32.Location = new System.Drawing.Point(10, 94);
            this.portESP32.Margin = new System.Windows.Forms.Padding(2);
            this.portESP32.Name = "portESP32";
            this.portESP32.Size = new System.Drawing.Size(192, 29);
            this.portESP32.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.SystemColors.Control;
            this.label2.Location = new System.Drawing.Point(6, 70);
            this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(38, 21);
            this.label2.TabIndex = 4;
            this.label2.Text = "Port";
            // 
            // lightoff
            // 
            this.lightoff.Image = global::TrainwareShappire.Properties.Resources.alarmOFF;
            this.lightoff.Location = new System.Drawing.Point(10, 256);
            this.lightoff.Margin = new System.Windows.Forms.Padding(2);
            this.lightoff.Name = "lightoff";
            this.lightoff.Size = new System.Drawing.Size(193, 102);
            this.lightoff.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.lightoff.TabIndex = 21;
            this.lightoff.TabStop = false;
            // 
            // panel3
            // 
            this.panel3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(30)))), ((int)(((byte)(56)))), ((int)(((byte)(82)))));
            this.panel3.Controls.Add(this.StatusRec);
            this.panel3.Controls.Add(this.label9);
            this.panel3.Controls.Add(this.btnSERVO);
            this.panel3.Controls.Add(this.label13);
            this.panel3.Controls.Add(this.degreeServo);
            this.panel3.Controls.Add(this.label12);
            this.panel3.Controls.Add(this.distUS);
            this.panel3.Controls.Add(this.label11);
            this.panel3.Controls.Add(this.suhuDHT);
            this.panel3.Controls.Add(this.label8);
            this.panel3.Controls.Add(this.label7);
            this.panel3.Controls.Add(this.btnLED3);
            this.panel3.Controls.Add(this.label6);
            this.panel3.Controls.Add(this.btnLED4);
            this.panel3.Controls.Add(this.CirBarPOT);
            this.panel3.Controls.Add(this.label5);
            this.panel3.Controls.Add(this.listbox_rec);
            this.panel3.Location = new System.Drawing.Point(214, 31);
            this.panel3.Margin = new System.Windows.Forms.Padding(2);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(746, 369);
            this.panel3.TabIndex = 5;
            // 
            // StatusRec
            // 
            this.StatusRec.AutoSize = true;
            this.StatusRec.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(243)))), ((int)(((byte)(181)))), ((int)(((byte)(25)))));
            this.StatusRec.Font = new System.Drawing.Font("Segoe UI", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.StatusRec.ForeColor = System.Drawing.Color.White;
            this.StatusRec.Location = new System.Drawing.Point(481, 328);
            this.StatusRec.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.StatusRec.Name = "StatusRec";
            this.StatusRec.Size = new System.Drawing.Size(166, 32);
            this.StatusRec.TabIndex = 38;
            this.StatusRec.Text = "Data Terakhir";
            this.StatusRec.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.BackColor = System.Drawing.Color.Transparent;
            this.label9.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.ForeColor = System.Drawing.Color.White;
            this.label9.Location = new System.Drawing.Point(483, 301);
            this.label9.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(76, 21);
            this.label9.TabIndex = 37;
            this.label9.Text = "Raw Data";
            // 
            // btnSERVO
            // 
            this.btnSERVO.AutoSize = true;
            this.btnSERVO.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(243)))), ((int)(((byte)(181)))), ((int)(((byte)(25)))));
            this.btnSERVO.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.btnSERVO.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnSERVO.FlatAppearance.BorderSize = 0;
            this.btnSERVO.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnSERVO.Font = new System.Drawing.Font("Segoe UI", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSERVO.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.btnSERVO.Location = new System.Drawing.Point(126, 330);
            this.btnSERVO.Margin = new System.Windows.Forms.Padding(2);
            this.btnSERVO.Name = "btnSERVO";
            this.btnSERVO.Size = new System.Drawing.Size(76, 30);
            this.btnSERVO.TabIndex = 22;
            this.btnSERVO.Text = "SET";
            this.btnSERVO.UseVisualStyleBackColor = false;
            this.btnSERVO.Click += new System.EventHandler(this.btnSERVO_Click);
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.BackColor = System.Drawing.Color.Transparent;
            this.label13.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label13.ForeColor = System.Drawing.Color.White;
            this.label13.Location = new System.Drawing.Point(73, 301);
            this.label13.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(104, 21);
            this.label13.TabIndex = 36;
            this.label13.Text = "Derajat Servo";
            this.label13.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // degreeServo
            // 
            this.degreeServo.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(17)))), ((int)(((byte)(41)))), ((int)(((byte)(64)))));
            this.degreeServo.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.degreeServo.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.degreeServo.ForeColor = System.Drawing.SystemColors.Window;
            this.degreeServo.Location = new System.Drawing.Point(45, 330);
            this.degreeServo.Margin = new System.Windows.Forms.Padding(2);
            this.degreeServo.Name = "degreeServo";
            this.degreeServo.Size = new System.Drawing.Size(76, 29);
            this.degreeServo.TabIndex = 22;
            this.degreeServo.Text = "0";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.BackColor = System.Drawing.Color.Transparent;
            this.label12.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label12.ForeColor = System.Drawing.Color.White;
            this.label12.Location = new System.Drawing.Point(240, 274);
            this.label12.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(232, 84);
            this.label12.TabIndex = 35;
            this.label12.Text = "Jumper yang perlu disesuaikan :\r\nJP 2 : Ultrasonic\r\nJP 4 : Potensiometer\r\nJP 7 : " +
    "Servo";
            this.label12.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // distUS
            // 
            this.distUS.AutoSize = true;
            this.distUS.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(243)))), ((int)(((byte)(181)))), ((int)(((byte)(25)))));
            this.distUS.Font = new System.Drawing.Font("Segoe UI", 19.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.distUS.ForeColor = System.Drawing.Color.White;
            this.distUS.Location = new System.Drawing.Point(356, 224);
            this.distUS.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.distUS.Name = "distUS";
            this.distUS.Size = new System.Drawing.Size(115, 37);
            this.distUS.TabIndex = 34;
            this.distUS.Text = "500 CM";
            this.distUS.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.BackColor = System.Drawing.Color.Transparent;
            this.label11.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label11.ForeColor = System.Drawing.Color.White;
            this.label11.Location = new System.Drawing.Point(273, 235);
            this.label11.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(70, 21);
            this.label11.TabIndex = 33;
            this.label11.Text = "Jarak US";
            this.label11.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // suhuDHT
            // 
            this.suhuDHT.AutoSize = true;
            this.suhuDHT.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(243)))), ((int)(((byte)(181)))), ((int)(((byte)(25)))));
            this.suhuDHT.Font = new System.Drawing.Font("Segoe UI", 19.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.suhuDHT.ForeColor = System.Drawing.Color.White;
            this.suhuDHT.Location = new System.Drawing.Point(388, 175);
            this.suhuDHT.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.suhuDHT.Name = "suhuDHT";
            this.suhuDHT.Size = new System.Drawing.Size(83, 37);
            this.suhuDHT.TabIndex = 32;
            this.suhuDHT.Text = "27 °C";
            this.suhuDHT.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BackColor = System.Drawing.Color.Transparent;
            this.label8.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.ForeColor = System.Drawing.Color.White;
            this.label8.Location = new System.Drawing.Point(273, 186);
            this.label8.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(112, 21);
            this.label8.TabIndex = 31;
            this.label8.Text = "Suhu Ruangan";
            this.label8.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.Color.Transparent;
            this.label7.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.ForeColor = System.Drawing.Color.White;
            this.label7.Location = new System.Drawing.Point(325, 25);
            this.label7.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(92, 21);
            this.label7.TabIndex = 30;
            this.label7.Text = "Kontrol LED";
            this.label7.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btnLED3
            // 
            this.btnLED3.AutoSize = true;
            this.btnLED3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(9)))), ((int)(((byte)(106)))), ((int)(((byte)(175)))));
            this.btnLED3.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.btnLED3.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnLED3.FlatAppearance.BorderSize = 0;
            this.btnLED3.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnLED3.Font = new System.Drawing.Font("Segoe UI", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnLED3.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.btnLED3.Location = new System.Drawing.Point(270, 111);
            this.btnLED3.Margin = new System.Windows.Forms.Padding(2);
            this.btnLED3.Name = "btnLED3";
            this.btnLED3.Size = new System.Drawing.Size(200, 32);
            this.btnLED3.TabIndex = 29;
            this.btnLED3.Text = "LED 3 ON";
            this.btnLED3.UseVisualStyleBackColor = false;
            this.btnLED3.Click += new System.EventHandler(this.btnLED3_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.Color.Transparent;
            this.label6.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.White;
            this.label6.Location = new System.Drawing.Point(73, 25);
            this.label6.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(110, 21);
            this.label6.TabIndex = 22;
            this.label6.Text = "Potensiometer";
            this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btnLED4
            // 
            this.btnLED4.AutoSize = true;
            this.btnLED4.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(9)))), ((int)(((byte)(106)))), ((int)(((byte)(175)))));
            this.btnLED4.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.btnLED4.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnLED4.FlatAppearance.BorderSize = 0;
            this.btnLED4.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnLED4.Font = new System.Drawing.Font("Segoe UI", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnLED4.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.btnLED4.Location = new System.Drawing.Point(270, 61);
            this.btnLED4.Margin = new System.Windows.Forms.Padding(2);
            this.btnLED4.Name = "btnLED4";
            this.btnLED4.Size = new System.Drawing.Size(200, 32);
            this.btnLED4.TabIndex = 22;
            this.btnLED4.Text = "LED 4 ON";
            this.btnLED4.UseVisualStyleBackColor = false;
            this.btnLED4.Click += new System.EventHandler(this.btnLED4_Click);
            // 
            // CirBarPOT
            // 
            this.CirBarPOT.AnimationFunction = WinFormAnimation.KnownAnimationFunctions.CircularEaseIn;
            this.CirBarPOT.AnimationSpeed = 500;
            this.CirBarPOT.BackColor = System.Drawing.Color.Transparent;
            this.CirBarPOT.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Bold);
            this.CirBarPOT.ForeColor = System.Drawing.Color.White;
            this.CirBarPOT.InnerColor = System.Drawing.Color.Transparent;
            this.CirBarPOT.InnerMargin = 0;
            this.CirBarPOT.InnerWidth = 0;
            this.CirBarPOT.Location = new System.Drawing.Point(20, 61);
            this.CirBarPOT.Margin = new System.Windows.Forms.Padding(0);
            this.CirBarPOT.MarqueeAnimationSpeed = 2000;
            this.CirBarPOT.Name = "CirBarPOT";
            this.CirBarPOT.OuterColor = System.Drawing.Color.FromArgb(((int)(((byte)(17)))), ((int)(((byte)(41)))), ((int)(((byte)(64)))));
            this.CirBarPOT.OuterMargin = -25;
            this.CirBarPOT.OuterWidth = 25;
            this.CirBarPOT.ProgressColor = System.Drawing.Color.FromArgb(((int)(((byte)(9)))), ((int)(((byte)(106)))), ((int)(((byte)(175)))));
            this.CirBarPOT.ProgressWidth = 25;
            this.CirBarPOT.SecondaryFont = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CirBarPOT.Size = new System.Drawing.Size(212, 212);
            this.CirBarPOT.StartAngle = 270;
            this.CirBarPOT.SubscriptColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.CirBarPOT.SubscriptMargin = new System.Windows.Forms.Padding(10, -35, 0, 0);
            this.CirBarPOT.SubscriptText = "";
            this.CirBarPOT.SuperscriptColor = System.Drawing.Color.FromArgb(((int)(((byte)(166)))), ((int)(((byte)(166)))), ((int)(((byte)(166)))));
            this.CirBarPOT.SuperscriptMargin = new System.Windows.Forms.Padding(10, 35, 0, 0);
            this.CirBarPOT.SuperscriptText = "";
            this.CirBarPOT.TabIndex = 28;
            this.CirBarPOT.Text = "3,3 V";
            this.CirBarPOT.TextMargin = new System.Windows.Forms.Padding(0);
            this.CirBarPOT.Value = 68;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.Color.Transparent;
            this.label5.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.Color.White;
            this.label5.Location = new System.Drawing.Point(483, 25);
            this.label5.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(76, 21);
            this.label5.TabIndex = 27;
            this.label5.Text = "Raw Data";
            // 
            // listbox_rec
            // 
            this.listbox_rec.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.5F);
            this.listbox_rec.FormattingEnabled = true;
            this.listbox_rec.ItemHeight = 16;
            this.listbox_rec.Location = new System.Drawing.Point(487, 50);
            this.listbox_rec.Name = "listbox_rec";
            this.listbox_rec.Size = new System.Drawing.Size(250, 244);
            this.listbox_rec.TabIndex = 26;
            // 
            // TrainwareShappire
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(96F, 96F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Dpi;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(960, 400);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel3);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "TrainwareShappire";
            this.Text = "TrainWareUDP";
            this.Load += new System.EventHandler(this.TrainwareShappire_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.lighton)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.lightoff)).EndInit();
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TextBox ipESP32;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button SetIpPortESP32;
        private System.Windows.Forms.TextBox portESP32;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button closeCTRL;
        private System.Windows.Forms.Button minCTRL;
        private System.Windows.Forms.PictureBox lightoff;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ListBox listbox_rec;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.TextBox degreeServo;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label suhuDHT;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button btnLED3;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button btnLED4;
        private CircularProgressBar.CircularProgressBar CirBarPOT;
        private System.Windows.Forms.Button btnSERVO;
        private System.Windows.Forms.PictureBox lighton;
        private System.Windows.Forms.Label StatusRec;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label ipPC;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.Button cp_ipPC;
        private System.Windows.Forms.Label distUS;
    }
}

