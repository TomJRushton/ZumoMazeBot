using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace ZumoGUI
{
    public partial class Form1 : Form
    {
        SerialPort port;
        string labelContents = "    ";
        public Form1()
        {
            InitializeComponent();
            //init();
            SerialPort.GetPortNames();
            this.KeyPreview = true;
            this.KeyDown += new KeyEventHandler(Form1_KeyDown);
            List<string> data = new List<string>();
            data.Add(" ");
            comboBox1.DataSource = data.Concat(SerialPort.GetPortNames()).ToList();
            Forwads.Enabled = false;
            backwards.Enabled = false;
            turnRight.Enabled = false;
            turnLeft.Enabled = false;
            adjustLeft.Enabled = false;
            adjustRight.Enabled = false;
            searchRoomLeft.Enabled = false;
            searchRoomRight.Enabled = false;
            turn180.Enabled = false;
        }

        private string LabelContents
        {
            get
            {
                //lock (dummy) { // make it thread safe
                return labelContents; //}
            }
            set
            {
                //lock (dummy) { // make it thread safe
                labelContents = value;// }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            //switch
            if (e.KeyCode == Keys.W)
            {
                port.Write("W");
                //Forwads.BackColor = Color.DarkBlue;
            }
            if (e.KeyCode == Keys.A)
            {
                port.Write("A");
            }
            if (e.KeyCode == Keys.S)
            {
                port.Write("S");
            }
            if (e.KeyCode == Keys.D)
            {
                port.Write("D");
            }
            if (e.KeyCode == Keys.Q)
            {
                port.Write("Q");
            }
            if (e.KeyCode == Keys.E)
            {
                port.Write("E");
            }
            if (e.KeyCode == Keys.B)
            {
                port.Write("B");
            }
            if (e.KeyCode == Keys.H)
            {
                port.Write("H");
            }
            if (e.KeyCode == Keys.K)
            {
                port.Write("K");
            }
            if (e.KeyCode == Keys.L)
            {
                port.Write("L");
            }
        }

        private void Forwads_Click(object sender, EventArgs e)
        {
            //port.Open();
            port.Write("W");
            //port.Close();
        }

        private void turnLeft_Click(object sender, EventArgs e)
        {
            //port.Open();
            port.Write("A");
            //port.Close();
        }

        private void turnRight_Click(object sender, EventArgs e)
        {
            //port.Open();
            port.Write("D");
            //port.Close();
        }

        private void backwards_Click(object sender, EventArgs e)
        {
            //port.Open();
            port.Write("S");
            //port.Close();
        }

        private void adjustLeft_Click(object sender, EventArgs e)
        {
            //port.Open();
            port.Write("K");
            //port.Close();
        }

        private void adjustRight_Click(object sender, EventArgs e)
        {
            //port.Open();
            port.Write("L");
           // port.Close();
        }

        private void searchRoomLeft_Click(object sender, EventArgs e)
        {
            port.Write("Q");
        }

        private void searchRoomRight_Click(object sender, EventArgs e)
        {
            port.Write("E");
        }

        private void turn180_Click(object sender, EventArgs e)
        {
            port.Write("B");
        }

        private void DataReceivedHandler(
            object sender,
            SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            string indata = sp.ReadLine();
            LabelContents = "Data Received:" + indata; // this event handler runs in a separate thread to the GUI, so might need the thread safety protections...
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            port.Close();
        }

        private void status_Click(object sender, EventArgs e)
        {

        }

        //private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        //{
        //    string portName = (string)comboBox1.SelectedItem;
        //    try
        //    {
        //        port.Close(); // should probably also tidy up the event handler and dispose of the port object 
        //    }
        //    catch (Exception err)
        //    {
        //        LabelContents = "not connected yet ";
        //    }
        //    Forwads.Enabled = false;
        //    backwards.Enabled = false;
        //    try
        //    {
        //        port = new SerialPort(portName, 9600);
        //        LabelContents = "connected to " + portName;
        //        port.Open();
        //        port.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);
        //        //timer1.Interval = 100;
        //        //timer1.Start();
        //        Forwads.Enabled = true;
        //        backwards.Enabled = true;
        //    }
        //    catch (Exception err)
        //    {
        //        LabelContents = "not connected yet ";
        //    }
        //}

        private void comboBox1_SelectedIndexChanged_1(object sender, EventArgs e)
        {
            
                string portName = (string)comboBox1.SelectedItem;
                try
                {
                    port.Close(); // should probably also tidy up the event handler and dispose of the port object 
                }
                catch (Exception err)
                {
                    LabelContents = "not connected yet ";
                }

                try
                {
                    port = new SerialPort(portName, 9600);
                    LabelContents = "connected to " + portName;
                    port.Open();
                    port.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);
                    Forwads.Enabled = true;
                    backwards.Enabled = true;
                    turnRight.Enabled = true;
                    turnLeft.Enabled = true;
                    adjustLeft.Enabled = true;
                    adjustRight.Enabled = true;
                    searchRoomLeft.Enabled = true;
                    searchRoomRight.Enabled = true;
                    turn180.Enabled = true;
            }
                catch (Exception err)
                {
                    LabelContents = "not connected yet ";
                }
            }


    }
}
