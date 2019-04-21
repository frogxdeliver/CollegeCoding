using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.ComponentModel;
using System.Collections;

namespace PetAPup
{
    public partial class managePage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            
        }

        //Opens the connection from the web.config
        private static string GetConnectionString()
        {
            return ConfigurationManager.ConnectionStrings["PetAPupDB"].ConnectionString;
        }

        protected void BtnAnon_Click(object sender, EventArgs e)
        {
            //Creates a anon user with the data they entered in the text field
            SqlConnection con = new SqlConnection(GetConnectionString());
            con.Open();
            string ins = "insert into tblUsers(UserName, Password, CreateDate, resolvedTicket, modifiedDate, modifiedBy, ticketDescription)values('', '', getdate(), 0, null, '', '" + TxtAnon.Text + "')";
            SqlCommand cmd = new SqlCommand(ins, con);
            cmd.ExecuteNonQuery();
            con.Close();
            

        }
    }
}