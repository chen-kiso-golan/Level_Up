--new Query for MiniProject
--יצירת טבלה חדה של פרטים
create table Form (Code int primary key identity, FirstName nvarchar(20), LastName nvarchar(20), Email nvarchar(10),password nvarchar(10),Comments nvarchar(150),JoinedNewsletter bit)


select * from Form
