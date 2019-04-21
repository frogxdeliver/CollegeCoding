use PetAPuppyLukasFuller

create table tblUsers(
	username varchar(10),
	password varchar(30),
	createDate date,
	resolvedTicket bit,
	modifiedDate varchar(15),
	modifiedBy varchar(10),
	ticketDescription varchar(500),
	priority varchar(6)
	/*PRIMARY KEY (username)*/
);