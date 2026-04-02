import java.util.*;

public class Codec {
    Map<String, String> map = new HashMap<>();
    int counter = 0;
    
    public String encode(String longUrl) {
        String key = String.valueOf(++counter);
        map.put(key, longUrl);
        return "http://tinyurl.com/" + key;
    }
    
    public String decode(String shortUrl) {
        String key = shortUrl.substring(shortUrl.lastIndexOf('/') + 1);
        return map.get(key);
    }
}
