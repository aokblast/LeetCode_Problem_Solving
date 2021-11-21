//
//Runtime 5
//Memory Usage 39.2

public class Codec {

    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        arr.add(longUrl);
        return "http://tinyurl.com/" + (arr.size() - 1);
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        return arr.get(Integer.valueOf(shortUrl.substring(19)));
    }
    ArrayList<String> arr = new ArrayList<String>();
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));