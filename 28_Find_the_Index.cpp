//Use standard library
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

//Logic run through the string
class Solution {
public:
    int strStr(string haystack, string needle) {
        int size1 = haystack.size();
        int size2 = needle.size();
        if (size2 > size1) // needle larger than haystack
            return -1;

        for (int i{}; i < size1; i++) {
            for (int j{}; j <= size2; j++) {
                if (j == size2) // run through the whole needle
                    return i;
                if (i + j == size1) // Not run through the whole needle but the
                                    // end of haystack.
                    return -1;
                if (haystack[i + j] !=
                    needle[j]) // Char in haystack match with char in needle
                               // break the loop if not match
                    break;
            }
        }
        return -1;
    }
};
