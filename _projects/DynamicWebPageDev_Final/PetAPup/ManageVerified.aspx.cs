using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;

namespace PetAPup
{

    public partial class ManageVerified : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            /*if (!IsPostBack)
            {
                BindCustomers();
            }*/
        }
        //Couldn't quite figure out the color change in time :/
        //https://www.youtube.com/watch?v=vgSEF7Z_wAQ
        //Opens the connection from the web.config
        /*private static string GetConnectionString()
        {
            return ConfigurationManager.ConnectionStrings["PetAPupDB"].ConnectionString;
        }

        private void BindCustomers()
        {
            DataTable dt = new DataTable();
            SqlConnection con = new SqlConnection(GetConnectionString());

            if(dt.Rows.Count > 0)
            {
                .DataSource = dt;

            }
            
        }

        protected void gvCustomers_RowDataBound(object sender, GridViewRowEventArgs e)
        {
            if (e.Row.RowType == DataControlRowType.DataRow)
            {
                //compares the createDate cell with the current date
                //FIX:      change to something that will grab the current date
                if (e.Row.Cells[2].Text.CompareTo("12-10-2018") == 0)
                {
                    e.Row.Cells[2].CssClass = "Red";
                }
            }

        }*/

    }
}