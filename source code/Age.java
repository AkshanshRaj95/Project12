import java.time.*;
class Age{
	public static void main(String ...ak){
		LocalDate d1=LocalDate.parse(ak[0]);
		LocalDate d2=LocalDate.now();
		Period per=Period.between(d1,d2);
		System.out.println("Your age is "+ per.getYears()+" year "+ per.getMonths()+"Months "+per.getDays()+"days");
	}
}