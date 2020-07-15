Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

 

Example 1:

Input: IP = "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:

Input: IP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:

Input: IP = "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.
 

Constraints:

IP consists only of English letters, digits and the characters "." and ":".

// String manapulation.
class Solution {
public:
    string validIPAddress(string IP) {
      bool ipv4 = CheckIfIpv4(IP);
      if (ipv4) {
        if (VerifyIpv4(IP)) return "IPv4";
      } else if (VerifyIpv6(IP)) {
        return "IPv6";
      }
      return "Neither"; 
    }
private:
    bool CheckIfIpv4(string IP) {
        if (IP.find('.') != std::string::npos) return true;
        std::cout << "IPV6" <<std::endl;
        return false;
    }
    bool VerifyIpv4(string IP) {
      std::cout << "Verify IPV4." << std::endl;
      IP += '.';
      vector<int> nums(4, 0);
      std::size_t pos = 0, next = 0;
      for (int i = 0; i < 4; i++) {
        next = IP.find('.', pos);
        std::cout << "Next: " << next << std::endl;
        if (next == std::string::npos) return false;
        string cur = IP.substr(pos, next - pos);
        std::cout << "cur: " << cur << std::endl;
        if (cur.size() == 0 ||
            (cur.size() > 1 && cur[0] == '0') ||
            cur.size() > 3) {
            return false;
        }
        for (char c : cur) {
            if (c >= '0' && c <= '9') continue;
            else return false;
        }
        nums[i] = stoi(cur); 
        pos = next + 1;
      }
      next =  IP.find('.', pos);
      if (next != std::string::npos) return false;
      for (int num : nums) {
        std::cout << num << std::endl;
        if (num > 255) return false;
      }
      return true;
    }
    
    bool VerifyIpv6(string IP) {
      IP += ":";
      std::size_t pos = 0, next = 0;
      for (int i = 0; i < 8; i++) {
        next = IP.find(':', pos);
        std::cout << "Next: " << next << std::endl;
        if (next == std::string::npos) return false;
        string cur = IP.substr(pos, next - pos);
        std::cout << "cur: " << cur << std::endl;
        if (cur.size() == 0 || cur.size() > 4) {
            return false;
        }
        for (char c : cur) {
            if ((c >= '0' && c <= '9') ||
                (c >= 'a' && c <= 'f') ||
                (c >= 'A' && c <= 'F')) {
                continue;
            } else {
                return false;
            }
        }
        pos = next + 1;          
      }
      next =  IP.find(':', pos);
      if (next != std::string::npos) return false;
      return true;
    }
};
