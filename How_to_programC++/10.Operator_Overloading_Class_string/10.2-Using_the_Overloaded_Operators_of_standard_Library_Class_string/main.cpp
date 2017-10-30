#include <iostream>
#include <string>

int main()
{
    std::string s1("happy");
    std::string s2(" birthday");
    std::string s3;

    // Test overloaded equality and relationl operators
    std::cout << "s1 is \"" << s1 << "\""
        << "\ns2 is \"" << s2
        << "\ns3 is \"" << s3
        << "\n\nThe results of comparing s2 and s1:"
        << "\ns2 == s1 yields " << ( s2 == s1 ? "true" : "false" )
        << "\ns2 != s1 yields " << ( s2 != s1 ? "true" : "false" )
        << "\ns2  > s1 yields " << ( s2 > s1 ? "true" : "false" )
        << "\ns2  < s1 yields " << ( s2 < s1 ? "true" : "false" )
        << "\ns2 >= s1 yields " << ( s2 >= s1 ? "true" : "false" )
        << "\ns2 <= s1 yields " << ( s2 <= s1 ? "true" : "false" );


    // test string member-function empty
    std::cout << "\n\nTesting s3.empty(): \n";

    if (s3.empty())
    {
        std::cout << "s3 is empty; assing s1 to s3;";
        s3 = s1;
        std::cout << "\ns3 is \"" << s3 << "\"";
    }

    // test overloaded string concatenation operator
    std::cout << "\ns1 += s2 yields s1 = ";
    s1 += s2;
    std::cout << s1;

    // test string member function substr
    std::cout << "The substring of s1 starting at location 0 for\n"
        << "14 characters, s1.substr(0,14), is:\n"
        << s1.substr(0,14) << std::endl;

    // test copy constructor
    std::string s4(s1);
    std::cout << "\ns4 = " << s4 << "\n\n";

    // test self-assignment copy operator
    std::cout << "assigning s4 to s4\n";
    s4 = s4;
    std::cout << "s4 = " << s4 << std::endl;

    // test using overloaded subscript operator to create lvalue
    s1[ 0 ] = 'H';
    s1[ 6 ] = 'B';
    std::cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is: " 
        << s1 << "\n\n";

    try
    {
        std::cout << "Attempt to assign 'd' to s1.at(30) yields:\n";
        s1.at(30); // ERROR: out_of_range exception
    }
    catch(const std::out_of_range &eor)
    {
        std::cout << "An exception occured: " << eor.what() << std::endl;
    }//end catch

    return 0;
}
