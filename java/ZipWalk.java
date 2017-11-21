import java.util.zip.ZipFile;
import java.util.zip.ZipEntry;
import java.io.IOException;
import java.io.InputStream;
import java.security.MessageDigest;
import java.util.Comparator;

public class ZipWalk{
    private static MessageDigest md;
    static {
        try{
            md = MessageDigest.getInstance("SHA1");
        } catch(Exception e) {
        
        }
    }
    public static void main(String[] args) {
        try(ZipFile zipFile = new ZipFile(args[0])){
            Comparator<ZipEntry> byName = (ze1, ze2) -> ze1.getName().compareTo(ze2.getName());
            zipFile.stream().sorted(byName).map(ze -> getJsonRep(zipFile,ze)).forEach(System.out::println);
        } catch(IOException e){
            e.printStackTrace();
        }
    }

    static String getJsonRep(ZipFile zf, ZipEntry ze){
        if(ze.isDirectory()){
            return String.format("{\"name\":\"%s\",\"size\":0,\"sha1\":\"0\"}",ze.getName());
        }

        String digest="";
        try(InputStream is=zf.getInputStream(ze)){
            byte[] buffer = new byte[8192];
            int n=0;
            while (n != -1) {
                n = is.read(buffer);
                if (n > 0) {
                    md.update(buffer, 0, n);
                }
            }
        } catch(Exception e){
            e.printStackTrace();
        }
        finally{
            digest=getHex(md.digest());
            md.reset();
        }
        
        return String.format("{\"name\":\"%s\",\"size\":%s,\"sha1\":\"%s\"}",ze.getName(),ze.getSize(),digest);
    }

    private static String getHex(byte[] b){
        String result = "";
        for (int i=0; i < b.length; i++) {
            result += Integer.toString( ( b[i] & 0xff ) + 0x100, 16).substring( 1 );
        }
        return result;
    }
}