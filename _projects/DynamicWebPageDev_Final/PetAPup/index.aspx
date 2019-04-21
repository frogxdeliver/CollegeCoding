<%@ Page Title="" Language="C#" MasterPageFile="~/SitePage.Master" AutoEventWireup="true" CodeBehind="index.aspx.cs" Inherits="PetAPup.homePage" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
    <style type="text/css">
        .auto-style3 {
            text-align: center;
            height: 26px;
        }
        .auto-style4 {
            height: 26px;
        }
    </style>
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="CPHmiddleContent" runat="server">
    <table class="auto-style2">
       <tr>
          <td class="auto-style3">&nbsp;</td>
          <td class="auto-style3">
              <asp:Login ID="Login1" runat="server" BackColor="#F7F6F3" BorderColor="#E6E2D8" BorderPadding="4" BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" Font-Size="0.8em" ForeColor="#333333" Height="164px" OnAuthenticate="Login1_Authenticate1" Width="248px">
                  <InstructionTextStyle Font-Italic="True" ForeColor="Black" />
                  <LoginButtonStyle BackColor="#FFFBFF" BorderColor="#CCCCCC" BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" Font-Size="0.8em" ForeColor="#284775" />
                  <TextBoxStyle Font-Size="0.8em" />
                  <TitleTextStyle BackColor="#5D7B9D" Font-Bold="True" Font-Size="0.9em" ForeColor="White" />
              </asp:Login>
           </td>
          <td class="auto-style4">&nbsp;</td>
       </tr>
       <tr>
          <td class="center">&nbsp;</td>
          <td class="center">&nbsp;</td>
          <td>
              &nbsp;</td>
       </tr>
       <tr>
          <td class="center">&nbsp;</td>
          <td class="center">&nbsp;</td>
          <td>&nbsp;</td>
       </tr>
       <tr>
          <td class="center">&nbsp;</td>
          <td class="center">&nbsp;</td>
          <td>&nbsp;</td>
       </tr>
       <tr>
          <td colspan="3">
              <br />
              <br />
              <br />
              <br />
              <br />
              <br />
              <br />
              <br />
              <asp:SiteMapPath ID="SiteMapPath1" runat="server">
              </asp:SiteMapPath>
              <br />
              <br />
              <br />
              <br />
              <br />
              <br />
              <br />
              <br />
          </td>
       </tr>
    </table>
</asp:Content>
