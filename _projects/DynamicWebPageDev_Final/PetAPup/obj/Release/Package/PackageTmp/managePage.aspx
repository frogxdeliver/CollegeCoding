<%@ Page Title="" Language="C#" MasterPageFile="~/SitePage.Master" AutoEventWireup="true" CodeBehind="managePage.aspx.cs" Inherits="PetAPup.managePage" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="CPHmiddleContent" runat="server">Manage Page
        <asp:SiteMapPath ID="SiteMapPath1" runat="server">
    </asp:SiteMapPath>
    <br/>
    <br/>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:PetAPupDB %>" SelectCommand="SELECT [username], [createDate], [resolvedTicket], [modifiedDate], [ticketDescription], [modifiedBy], [priority] FROM [tblUsers] ORDER BY [resolvedTicket], [modifiedBy], [createDate]"></asp:SqlDataSource>
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" BackColor="#CCCCCC" BorderColor="#999999" BorderStyle="Solid" BorderWidth="3px" CellPadding="4" CellSpacing="2" DataSourceID="SqlDataSource1" ForeColor="Black">
            <Columns>
                <asp:BoundField DataField="username" HeaderText="username" SortExpression="username" />
                <asp:BoundField DataField="createDate" HeaderText="createDate" SortExpression="createDate" />
                <asp:CheckBoxField DataField="resolvedTicket" HeaderText="resolvedTicket" SortExpression="resolvedTicket" />
                <asp:BoundField DataField="modifiedDate" HeaderText="modifiedDate" SortExpression="modifiedDate" />
                <asp:BoundField DataField="ticketDescription" HeaderText="ticketDescription" SortExpression="ticketDescription" />
                <asp:BoundField DataField="modifiedBy" HeaderText="modifiedBy" SortExpression="modifiedBy" />
                <asp:BoundField DataField="priority" HeaderText="priority" SortExpression="priority" />
            </Columns>
            <FooterStyle BackColor="#CCCCCC" />
            <HeaderStyle BackColor="Black" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#CCCCCC" ForeColor="Black" HorizontalAlign="Left" />
            <RowStyle BackColor="White" />
            <SelectedRowStyle BackColor="#000099" Font-Bold="True" ForeColor="White" />
            <SortedAscendingCellStyle BackColor="#F1F1F1" />
            <SortedAscendingHeaderStyle BackColor="#808080" />
            <SortedDescendingCellStyle BackColor="#CAC9C9" />
            <SortedDescendingHeaderStyle BackColor="#383838" />
        </asp:GridView>


    <br/>
    <br/>
    <h2>Anonymous ticket</h2>
    <asp:TextBox ID="TxtAnon" runat="server" Height="102px" Width="480px" TextMode="MultiLine" ></asp:TextBox>
    <asp:Button ID="BtnAnon" runat="server" Text="Create" OnClick="BtnAnon_Click" />
</asp:Content>
