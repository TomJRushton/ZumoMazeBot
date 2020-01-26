namespace ZumoGUI
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
            this.Forwads = new System.Windows.Forms.Button();
            this.turnLeft = new System.Windows.Forms.Button();
            this.backwards = new System.Windows.Forms.Button();
            this.turnRight = new System.Windows.Forms.Button();
            this.searchRoomRight = new System.Windows.Forms.Button();
            this.searchRoomLeft = new System.Windows.Forms.Button();
            this.adjustLeft = new System.Windows.Forms.Button();
            this.turn180 = new System.Windows.Forms.Button();
            this.returnHome = new System.Windows.Forms.Button();
            this.adjustRight = new System.Windows.Forms.Button();
            this.adjustL = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.status = new System.Windows.Forms.Label();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // Forwads
            // 
            this.Forwads.Location = new System.Drawing.Point(126, 87);
            this.Forwads.Name = "Forwads";
            this.Forwads.Size = new System.Drawing.Size(83, 70);
            this.Forwads.TabIndex = 0;
            this.Forwads.Text = "W";
            this.Forwads.UseVisualStyleBackColor = true;
            this.Forwads.Click += new System.EventHandler(this.Forwads_Click);
            // 
            // turnLeft
            // 
            this.turnLeft.Location = new System.Drawing.Point(25, 178);
            this.turnLeft.Name = "turnLeft";
            this.turnLeft.Size = new System.Drawing.Size(83, 70);
            this.turnLeft.TabIndex = 1;
            this.turnLeft.Text = "A";
            this.turnLeft.UseVisualStyleBackColor = true;
            this.turnLeft.Click += new System.EventHandler(this.turnLeft_Click);
            // 
            // backwards
            // 
            this.backwards.Location = new System.Drawing.Point(126, 178);
            this.backwards.Name = "backwards";
            this.backwards.Size = new System.Drawing.Size(83, 70);
            this.backwards.TabIndex = 2;
            this.backwards.Text = "S";
            this.backwards.UseVisualStyleBackColor = true;
            this.backwards.Click += new System.EventHandler(this.backwards_Click);
            // 
            // turnRight
            // 
            this.turnRight.Location = new System.Drawing.Point(232, 178);
            this.turnRight.Name = "turnRight";
            this.turnRight.Size = new System.Drawing.Size(83, 70);
            this.turnRight.TabIndex = 3;
            this.turnRight.Text = "D";
            this.turnRight.UseVisualStyleBackColor = true;
            this.turnRight.Click += new System.EventHandler(this.turnRight_Click);
            // 
            // searchRoomRight
            // 
            this.searchRoomRight.Location = new System.Drawing.Point(247, 102);
            this.searchRoomRight.Name = "searchRoomRight";
            this.searchRoomRight.Size = new System.Drawing.Size(68, 55);
            this.searchRoomRight.TabIndex = 4;
            this.searchRoomRight.Text = "E";
            this.searchRoomRight.UseVisualStyleBackColor = true;
            this.searchRoomRight.Click += new System.EventHandler(this.searchRoomRight_Click);
            // 
            // searchRoomLeft
            // 
            this.searchRoomLeft.Location = new System.Drawing.Point(25, 102);
            this.searchRoomLeft.Name = "searchRoomLeft";
            this.searchRoomLeft.Size = new System.Drawing.Size(68, 55);
            this.searchRoomLeft.TabIndex = 5;
            this.searchRoomLeft.Text = "Q";
            this.searchRoomLeft.UseVisualStyleBackColor = true;
            this.searchRoomLeft.Click += new System.EventHandler(this.searchRoomLeft_Click);
            // 
            // adjustLeft
            // 
            this.adjustLeft.Location = new System.Drawing.Point(40, 345);
            this.adjustLeft.Name = "adjustLeft";
            this.adjustLeft.Size = new System.Drawing.Size(83, 70);
            this.adjustLeft.TabIndex = 6;
            this.adjustLeft.Text = "K";
            this.adjustLeft.UseVisualStyleBackColor = true;
            this.adjustLeft.Click += new System.EventHandler(this.adjustLeft_Click);
            // 
            // turn180
            // 
            this.turn180.Location = new System.Drawing.Point(541, 29);
            this.turn180.Name = "turn180";
            this.turn180.Size = new System.Drawing.Size(83, 70);
            this.turn180.TabIndex = 7;
            this.turn180.Text = "B (180)";
            this.turn180.UseVisualStyleBackColor = true;
            this.turn180.Click += new System.EventHandler(this.turn180_Click);
            // 
            // returnHome
            // 
            this.returnHome.Location = new System.Drawing.Point(630, 29);
            this.returnHome.Name = "returnHome";
            this.returnHome.Size = new System.Drawing.Size(83, 70);
            this.returnHome.TabIndex = 8;
            this.returnHome.Text = "H";
            this.returnHome.UseVisualStyleBackColor = true;
            // 
            // adjustRight
            // 
            this.adjustRight.Location = new System.Drawing.Point(192, 345);
            this.adjustRight.Name = "adjustRight";
            this.adjustRight.Size = new System.Drawing.Size(83, 70);
            this.adjustRight.TabIndex = 9;
            this.adjustRight.Text = "L";
            this.adjustRight.UseVisualStyleBackColor = true;
            this.adjustRight.Click += new System.EventHandler(this.adjustRight_Click);
            // 
            // adjustL
            // 
            this.adjustL.AutoSize = true;
            this.adjustL.BackColor = System.Drawing.SystemColors.ControlLight;
            this.adjustL.Location = new System.Drawing.Point(40, 322);
            this.adjustL.Name = "adjustL";
            this.adjustL.Size = new System.Drawing.Size(75, 17);
            this.adjustL.TabIndex = 10;
            this.adjustL.Text = "Adjust Left";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.ControlLight;
            this.label1.Location = new System.Drawing.Point(189, 322);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(84, 17);
            this.label1.TabIndex = 11;
            this.label1.Text = "Adjust Right";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.SystemColors.ControlLight;
            this.label2.Location = new System.Drawing.Point(230, 79);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(108, 17);
            this.label2.TabIndex = 12;
            this.label2.Text = "Search Room R";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.SystemColors.ControlLight;
            this.label3.Location = new System.Drawing.Point(6, 79);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(106, 17);
            this.label3.TabIndex = 13;
            this.label3.Text = "Search Room L";
            // 
            // status
            // 
            this.status.AutoSize = true;
            this.status.BackColor = System.Drawing.SystemColors.ControlLight;
            this.status.ForeColor = System.Drawing.SystemColors.ControlText;
            this.status.Location = new System.Drawing.Point(381, 140);
            this.status.Name = "status";
            this.status.Size = new System.Drawing.Size(48, 17);
            this.status.TabIndex = 14;
            this.status.Text = "Status";
            this.status.Click += new System.EventHandler(this.status_Click);
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(384, 53);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(121, 24);
            this.comboBox1.TabIndex = 15;
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged_1);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.SystemColors.ControlDark;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(121, 18);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(107, 29);
            this.label4.TabIndex = 16;
            this.label4.Text = "Controls";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.SystemColors.ControlLight;
            this.label5.Location = new System.Drawing.Point(397, 29);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(96, 17);
            this.label5.TabIndex = 17;
            this.label5.Text = "Port Selection";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(365, 178);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(241, 22);
            this.textBox1.TabIndex = 18;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.status);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.adjustL);
            this.Controls.Add(this.adjustRight);
            this.Controls.Add(this.returnHome);
            this.Controls.Add(this.turn180);
            this.Controls.Add(this.adjustLeft);
            this.Controls.Add(this.searchRoomLeft);
            this.Controls.Add(this.searchRoomRight);
            this.Controls.Add(this.turnRight);
            this.Controls.Add(this.backwards);
            this.Controls.Add(this.turnLeft);
            this.Controls.Add(this.Forwads);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Forwads;
        private System.Windows.Forms.Button turnLeft;
        private System.Windows.Forms.Button backwards;
        private System.Windows.Forms.Button turnRight;
        private System.Windows.Forms.Button searchRoomRight;
        private System.Windows.Forms.Button searchRoomLeft;
        private System.Windows.Forms.Button adjustLeft;
        private System.Windows.Forms.Button turn180;
        private System.Windows.Forms.Button returnHome;
        private System.Windows.Forms.Button adjustRight;
        private System.Windows.Forms.Label adjustL;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label status;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBox1;
    }
}

