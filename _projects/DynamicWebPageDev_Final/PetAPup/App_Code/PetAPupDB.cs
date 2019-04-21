using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.ComponentModel;
using System.Collections;

namespace PetAPup.App_Code
{
    public class PetAPupDB
    {
        //Opens the connection from the web.config
        private static string GetConnectionString()
        {
            return ConfigurationManager.ConnectionStrings["PetAPupDB"].ConnectionString;
        }

        //Validates the user input
        public bool ValidateUserLogin(string UserName, string Password)
        {
            SqlConnection con = new SqlConnection(GetConnectionString());

            string sel = "select * from tblUsers where username = @UserName and Password = @Password";

            SqlCommand cmd = new SqlCommand(sel, con);

            cmd.Parameters.AddWithValue("UserName", UserName);
            cmd.Parameters.AddWithValue("Password", Password);

            con.Open();

            SqlDataReader dr = cmd.ExecuteReader(CommandBehavior.CloseConnection);

            bool foundUser = false;

            while (dr.Read())
            {
                foundUser = true;
            }

            dr.Close();

            return foundUser;
        }


    }
}