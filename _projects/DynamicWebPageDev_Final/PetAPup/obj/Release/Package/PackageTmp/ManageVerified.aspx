<%@ Page Title="" Language="C#" MasterPageFile="~/SitePage.Master" AutoEventWireup="true" CodeBehind="ManageVerified.aspx.cs" Inherits="PetAPup.ManageVerified" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="CPHmiddleContent" runat="server">

    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:PetAPupDB %>" 
        SelectCommand="SELECT [username], [resolvedTicket], [createDate], [modifiedDate], [modifiedBy], [ticketDescription], [priority] FROM [tblUsers] ORDER BY [resolvedTicket] DESC, [modifiedDate], [createDate]"
        UpdateCommand="UPDATE tblUsers SET resolvedTicket = @ResolvedTicket, modifiedDate = @modifiedDate, ticketDescription = @ticketDescription, modifiedBy = @modifiedBy WHERE username = @username"
        InsertCommand="INSERT INTO [tblUsers] ([username], [createDate], [resolvedTicket], [modifiedDate], [ticketDescription], [modifiedBy]) VALUES (@username, @createDate, @resolvedTicket, @modifiedDate, @ticketDescription, @modifiedBy)">
        <InsertParameters>
            <asp:Parameter Name="username" Type="String" />
            <asp:Parameter Name="createDate" Type="String" />
            <asp:Parameter Name="resolvedTicket" Type="Boolean" />
            <asp:Parameter Name="modifiedDate" Type="String" />
            <asp:Parameter Name="ticketDescription" Type="String" />
            <asp:Parameter Name="modifiedBy" Type="String" />
        </InsertParameters>
    </asp:SqlDataSource>
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataSourceID="SqlDataSource1" BackColor="White" BorderColor="#999999" BorderStyle="Solid" BorderWidth="1px" CellPadding="3" ForeColor="Black" GridLines="Vertical">
            <AlternatingRowStyle BackColor="#CCCCCC" />
            <Columns>
                <asp:BoundField DataField="username" HeaderText="username" SortExpression="username" />
                <asp:CheckBoxField DataField="resolvedTicket" HeaderText="resolvedTicket" SortExpression="resolvedTicket" />
                <asp:BoundField DataField="createDate" HeaderText="createDate" SortExpression="createDate" />
                <asp:BoundField DataField="modifiedDate" HeaderText="modifiedDate" SortExpression="modifiedDate" />
                <asp:BoundField DataField="modifiedBy" HeaderText="modifiedBy" SortExpression="modifiedBy" />
                <asp:BoundField DataField="ticketDescription" HeaderText="ticketDescription" SortExpression="ticketDescription" />
                <asp:BoundField DataField="priority" HeaderText="priority" SortExpression="priority" />
                <asp:CommandField ShowEditButton="True" />
            </Columns>
            <FooterStyle BackColor="#CCCCCC" />
            <HeaderStyle BackColor="Black" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#999999" ForeColor="Black" HorizontalAlign="Center" />
            <SelectedRowStyle BackColor="#000099" Font-Bold="True" ForeColor="White" />
            <SortedAscendingCellStyle BackColor="#F1F1F1" />
            <SortedAscendingHeaderStyle BackColor="#808080" />
            <SortedDescendingCellStyle BackColor="#CAC9C9" />
            <SortedDescendingHeaderStyle BackColor="#383838" />
        </asp:GridView>


</asp:Content>
