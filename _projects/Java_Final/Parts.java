//Parts.java
public class Parts
{
	private String name;
	private String ID;
	private double price;
	private double amount; //quantity on hand

	public Parts()
	{
		name = "";
		ID = "";
		price = 0.0;
		amount = 0.0;
	}
	public Parts(String newName, String newID)
	{
		name = newName;
		ID = newID;
	}

	public String getName()
	{
		return name;
	}
	public String getID()
	{
		return ID;
	}
	public double getPrice()
	{
		return price;
	}
	public double getAmount()
	{
		return amount;
	}

	public void setName(String newName)
	{
		name = newName;
	}
	public void setID(String newID)
	{
		ID = newID;
	}
	public void setPrice(double newPrice)
	{
		price = newPrice;
	}
	public void setAmount(double newAmount)
	{
		amount = newAmount;
	}

	public String toString()
	{
		return "Name: " + name + "\t" + "ID: " + ID + "\t" + "Price: " + price +  "\t" + "Amount: " + amount;
	}
}