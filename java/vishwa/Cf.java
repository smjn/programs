import java.io.*;

class Cf {
	public static void main(String[] args) throws Exception {
		//System.setOut(new PrintStream(new FileOutputStream("test.txt")));

		try {
			String line;
			//String cmd = "bash -c 'cf ssh ssh-proxy-server -c \"find .\"'";
			String cmd = "cf ssh ssh-proxy-server -c ";
			Process p = Runtime.getRuntime().exec(new String[]{"cf","ssh", "ssh-proxy-server", "-c", "\"find .\""});

			BufferedReader in = new BufferedReader(
					new InputStreamReader(p.getInputStream()) );
			while ((line = in.readLine()) != null) {
				System.out.println(line);
			}
			in.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
}
