using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;


namespace DatabaceGUI_Csharp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Label1_Click(object sender, EventArgs e)
        {

        }

        private void Button1_Click(object sender, EventArgs e)
        {
            try
            {
                string myConnection = "datasource=localhost;port=3306;username=;password=";
                MySqlConnection myConn = new MySqlConnection(myConnection);
                MySqlCommand SelectCommand = new MySqlCommand("select * from software_proj.admin_table where Admin_ID ='" + this.username_txt.Text + "' and Password='" + this.password_txt.Text + "';",myConn);
                MySqlDataReader myReader;
                myConn.Open();
                myReader = SelectCommand.ExecuteReader();
                int count = 0;
                
                while(myReader.Read())
                {
                    count = count = 1;
                }
                if (count == 1)
                {
                    MessageBox.Show("Username and Password is correct");
                }
                else if (count > 1)
                {
                    MessageBox.Show("Duplicate Username and Password...Access Denied!");
                }
                else
                    MessageBox.Show("Username and Password is not correct...Please Try Again");
                myConn.Close();
            }
            catch(Exception ex)
            {
                _ = MessageBox.Show(ex.Message);
            }
            //this.Hide();  
            //Form2 f2 = new Form2();
            //f2.ShowDialog();

        }
    }
}
