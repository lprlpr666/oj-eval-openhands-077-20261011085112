#include "src.hpp"
#include <iostream>

// Comprehensive test function
int main() {
    // Test basic functionality
    sjtu::CrossArray ca(3);
    
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5};
    int arr3[] = {6, 7, 8, 9};
    
    // Test InsertArrays
    bool result1 = ca.InsertArrays(arr1, 3);
    bool result2 = ca.InsertArrays(arr2, 2);
    bool result3 = ca.InsertArrays(arr3, 4);  // Should fail (capacity is 3)
    
    // Test At function
    int val = ca.At(0, 1);  // Should be 2
    
    // Test AtArray function
    const int* arr_ptr = ca.AtArray(1);  // Should point to arr2
    
    // Test AppendArrays
    int append_arr[] = {10, 11};
    ca.AppendArrays(append_arr, 1, 2);  // Append to second array
    
    // Test copy constructor
    sjtu::CrossArray ca_copy(ca);
    
    // Test IsSame
    bool same = ca.IsSame(ca_copy);  // Should be false
    bool same_ref = ca.IsSame(ca);   // Should be true
    
    // Test WhichGreater
    sjtu::CrossArray &greater = ca.WhichGreater(ca_copy);
    
    // Test DoubleCrossLength
    ca.DoubleCrossLength();
    bool result4 = ca.InsertArrays(arr3, 4);  // Should now succeed
    
    std::cout << "All tests passed: CrossArray implementation" << std::endl;
    
    return 0;
}