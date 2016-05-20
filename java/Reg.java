import java.util.regex.*;

class Reg{
	public static void main(String[] args) {
		Pattern p = Pattern.compile("^\\S+@\\S+[.]\\S+$");
		Matcher m = p.matcher("abc@def.com");
		
		if(m.matches())	System.out.println("Found!");
		else	System.out.println("Not found!");

	}
}