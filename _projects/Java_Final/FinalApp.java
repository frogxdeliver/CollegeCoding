//FinalApp.java
public class FinalApp //Client
{
	public static void main(String [] args)
	{
	//Customers
		Customer c1 = new Customer("001");
		c1.setName("John");
		c1.setNumber("1");

		Customer c2 = new Customer("002");
		c2.setName("Jacob");
		c2.setNumber("2");

		Customer c3 = new Customer("003");
		c3.setName("Jingle");
		c3.setNumber("3");

		Customer c4 = new Customer("004");
		c4.setName("Hymer");
		c4.setNumber("4");

	//Parts
		Parts p1 = new Parts("Generic_Stuff_#1", "00001");
		p1.setPrice(10);
		p1.setAmount(25);

		Parts p2 = new Parts("Generic_Stuff_#2", "00002");
		p2.setPrice(50);
		p2.setAmount(5);

		Parts p3 = new Parts("Generic_Stuff_#3", "00003");
		p3.setPrice(100);
		p3.setAmount(7);

		Parts p4 = new Parts("Generic_Stuff_#4", "00004");
		p4.setPrice(200);
		p4.setAmount(11);

		Parts p5 = new Parts("Generic_Stuff_#5", "00005");
		p5.setPrice(250);
		p5.setAmount(10);

		Parts p6 = new Parts("Generic_Stuff_#6", "00006");
		p6.setPrice(600);
		p6.setAmount(9);

		Parts p7 = new Parts("Generic_Stuff_#7", "00007");
		p7.setPrice(700);
		p7.setAmount(8);

		Parts p8 = new Parts("Generic_Stuff_#8", "00008");
		p8.setPrice(800);
		p8.setAmount(5);

		Parts p9 = new Parts("Generic_Stuff_#9", "00009");
		p9.setPrice(20000);
		p9.setAmount(5);

		Parts p10 = new Parts("Generic_Stuff_#10", "00010");
		p10.setPrice(50000);
		p10.setAmount(10);

	//Transactions
		Transaction t1 = new Transaction();
		t1.setCID(c1.getID());
		t1.setTID("3827");
		t1.setDate("5/2/2016");
		t1.setPartNum(p1.getID());
		t1.setAmount(10 - p1.getAmount());
		p1.setAmount(t1.getAmount());

		Transaction t2 = new Transaction();
		t2.setCID(c1.getID());
		t2.setTID("5682");
		t2.setDate("5/2/2016");
		t2.setPartNum(p2.getID());
		t2.setAmount(5 - p2.getAmount());
		p2.setAmount(t2.getAmount());

		Transaction t3 = new Transaction();
		t3.setCID(c1.getID());
		t3.setTID("9174");
		t3.setDate("5/2/2016");
		t3.setPartNum(p3.getID());
		t3.setAmount(6 - p3.getAmount());
		p3.setAmount(p3.getAmount());

		Transaction t4 = new Transaction();
		t4.setCID(c1.getID());
		t4.setTID("8726");
		t4.setDate("5/2/2016");
		t4.setPartNum(p4.getID());
		t4.setAmount(6 - p4.getAmount());
		p4.setAmount(t4.getAmount());

		Transaction t5 = new Transaction();
		t5.setCID(c1.getID());
		t5.setTID("3827");
		t5.setDate("5/2/2016");
		t5.setPartNum(p5.getID());
		t5.setAmount(8 - p5.getAmount());
		p5.setAmount(t5.getAmount());


		System.out.println(p1.toString() + "\n");
		System.out.println(p2.toString() + "\n");
		System.out.println(p3.toString() + "\n");
		System.out.println(p4.toString() + "\n");
		System.out.println(p5.toString() + "\n");
		System.out.println(p6.toString() + "\n");
		System.out.println(p7.toString() + "\n");
		System.out.println(p8.toString() + "\n");
		System.out.println(p9.toString() + "\n");
		System.out.println(p10.toString() + "\n");
	}
}