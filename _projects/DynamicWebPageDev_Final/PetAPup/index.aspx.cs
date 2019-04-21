
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;

namespace PetAPup
{
    public partial class homePage : System.Web.UI.Page
    {
        //public bool ValidateForButton = false;

        protected void Page_Load(object sender, EventArgs e)
        {

        }

        //Not sure how you'd have one validator for 2 different text fields...

        //At least 5 characters on Username
        /*
        protected void UsernameLengthValidator_ServerValidate(object source, ServerValidateEventArgs args)
        {
            args.IsValid = (args.Value.Length >= 5);
        }
        
        protected void PasswordValidator_ServerValidate(object source, ServerValidateEventArgs args)
        {
            //At least 8 length on Password
            args.IsValid = (args.Value.Length >= 8);

            //Reference: https://www.tutorialride.com/asp-net/customvalidator-in-asp-net.htm
            //Checks for 1 uppercase letter on Password
            string inputData = args.Value;
            args.IsValid = false;
            bool upperCase = false;
            foreach(char ch in inputData)
            {
                if (ch >= 'A' && ch <= 'Z')
                {
                    upperCase = true;
                    
                }
            }
            if (!upperCase) return;
        }*/

        
        /*
        protected void BtnSubmit_Click(object sender, EventArgs e)
        {
            /*if (ValidateForButton)
            {
                Response.Redirect("managePage.aspx");
            }*/
            /*
            App_Code.PetAPupDB DBLayer;

            DBLayer = new App_Code.PetAPupDB();

            bool foundUser = DBLayer.ValidateUserLogin(TxtbUsername.Text, TxtbPass.Text);

            if (foundUser)
            {
                //true
                Response.Redirect("managePage.aspx");
            }
            else
            {
                //false
                
            }

            //Response.Write("/nEnd of Code");

        }*/

        protected void Login1_Authenticate1(object sender, AuthenticateEventArgs e)
        {
            //Server.Transfer("manageVerified.aspx", true);
            Response.Redirect("manageVerified.aspx");
            //Session["UserName"] = User.Identity.Name;
        }

    }
}