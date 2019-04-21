using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace PetAPup
{
    public partial class siteMap : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        //Reference: https://docs.microsoft.com/en-us/dotnet/api/system.web.ui.page.stylesheettheme?redirectedfrom=MSDN&view=netframework-4.7.2#System_Web_UI_Page_StyleSheetTheme
        //Change the theme
        /*I have a little bit of trouble with the programming side, so it doesn't change it to Winter... I'm not sure how I'd do that.
        In my head I have an idea, but writing it down just doesn't seem to work.. I would need to declare the variable for the date,
        somehow retrieve it, then have an if loop that will first check if it's December 31st
        else
        return fall, like it is now... But for some reason I can't figure it out... It's basic programming, but sometimes I just forget these things... Idk*/
        public override String StyleSheetTheme
        {
            
            get { return "Fall"; }
        }
    }
}