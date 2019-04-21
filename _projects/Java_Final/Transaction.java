//Transaction.java
public class Transaction
{
	private String cID; //customerID
	private String tID; //transactionID
	private String date; //transactionDate
	private String partNum; //partNumber
	private double amount; //quantity purchased

	public Transaction()
	{
		cID = "";
		tID = "";
		date = "";
		partNum = "";
		amount = 0.0;
	}

	public String getCID()
	{
		return cID;
	}
	public String getTID()
	{
		return tID;
	}
	public String getDate()
	{
		return date;
	}
	public String getPartNum()
	{
		return partNum;
	}
	public double getAmount()
	{
		return amount;
	}

	public void setCID(String newCID)
	{
		cID = newCID;
	}
	public void setTID(String newTID)
	{
		tID = newTID;
	}
	public void setDate(String newDate)
	{
		date = newDate;
	}
	public void setPartNum(String newNum)
	{
		partNum = newNum;
	}
	public void setAmount(double newAmount)
	{
		amount = newAmount;
	}
}