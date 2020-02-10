class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0;
        int i2 = 0;
        version1.push_back('.');
        version2.push_back('.');
        int num1 = 0;
        int num2 = 0;
        int next1 = 0;
        int next2 = 0;
        while(i1 < version1.size() || i2 < version2.size())
        {
            if(i1 >= version1.size()) num1 = 0;
            else
            {
                next1 = version1.find('.', i1);
                num1 = stoi(version1.substr(i1, next1-i1));
            }
            if(i2 >= version2.size()) num2 = 0;   
            else
            {
                next2 = version2.find('.', i2);
                num2 = stoi(version2.substr(i2, next2-i2));
            }
            
            if(num1 < num2)
                return -1;
            else if(num1 > num2)
                return 1;
            i1 = next1+1;
            i2 = next2+1;
        }
        
        return 0;
    }
};

// Sol2: use stringstream.
class Solution {
public:
    int compareVersion(string version1, string version2) {
      stringstream str1(version1 + '.');
      stringstream str2(version2 + '.');
      int val1 = 0, val2 = 0;
      char dot;
      while(str1.good() || str2.good()) {
          if(str1.good()) str1 >> val1 >> dot;
          if(str2.good()) str2 >> val2 >> dot;
          if (val1 > val2) return 1;
          if (val1 < val2) return -1;
          val1 = 0, val2 = 0;
      }
      return 0;
    }
};
