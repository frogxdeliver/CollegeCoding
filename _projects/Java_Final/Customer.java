//Customer.java
public class Customer
{
	private String name;
	private String number;
	private String ID;

	public Customer()
	{
		name = "";
		number = "";
		ID = "";
	}
	public Customer(String newID)
	{
		ID = newID;
	}

	public String getName()
	{
		return name;
	}
	public String getNumber()
	{
		return number;
	}
	public String getID()
	{
		return ID;
	}

	public void setName(String newName)
	{
		name = newName;
	}
	public void setNumber(String newNum)
	{
		number = newNum;
	}
	public void setID(String newID)
	{
		ID = newID;
	}

	public String toString()
	{
		return "Name: " + name + "\n" + "Number: " + number + "\n" + "ID: " + ID;
	}
}