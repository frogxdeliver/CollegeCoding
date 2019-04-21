<%@ Page Title="" Language="C#" MasterPageFile="~/SitePage.Master" AutoEventWireup="true" CodeBehind="siteMap.aspx.cs" Inherits="PetAPup.siteMap"  %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="CPHmiddleContent" runat="server">
    
    <asp:Label runat="server" Text="Theme (Blue Winter, Black Normal)"></asp:Label><br />
    
    <div _designerregion="0">
        <asp:TreeView ID="TreeView1" runat="server" DataSourceID="SiteMapDataSource1">
        </asp:TreeView>
        <asp:SiteMapDataSource ID="SiteMapDataSource1" runat="server" />
    </div>
</asp:Content>
