#include <iostream>
#include <string>
#include <stdexcept>
#include "LinkedList.hpp"

using namespace std;

int main() {
    cout << "==================== INT LIST ====================\n";
    LinkedList<int> li;

    cout << "Empty list initial state:\n";
    cout << "isEmpty(): " << boolalpha << li.isEmpty() << "\n";
    cout << "getLength(): " << li.getLength() << "\n";
    cout << li << "\n";

    cout << "Calling clear() on empty list:\n";
    li.clear();
    cout << "After clear -> length: " << li.getLength()
         << ", isEmpty(): " << li.isEmpty() << "\n";
    cout << li << "\n";

    cout << "getElement(0) on empty list (should throw):\n";
    try { cout << li.getElement(0) << "\n"; }
    catch (const exception& e) { cout << "Caught exception: " << e.what() << "\n"; }

    cout << "replace(0, 99) on empty list (should throw):\n";
    try { li.replace(0, 99); }
    catch (const exception& e) { cout << "Caught exception: " << e.what() << "\n"; }

    cout << "\nAppending elements: 10, 20, 30, 40\n";
    li.append(10); li.append(20); li.append(30); li.append(40);
    cout << li;
    cout << "Length: " << li.getLength() << "\n";

    cout << "\nValid getElement calls:\n";
    cout << "getElement(0): " << li.getElement(0) << "\n";
    cout << "getElement(2): " << li.getElement(2) << "\n";
    cout << "getElement(last): " << li.getElement(li.getLength() - 1) << "\n";

    cout << "\nInvalid getElement calls:\n";
    try { cout << "getElement(-1): " << li.getElement(-1) << "\n"; }
    catch (const exception& e) { cout << "Caught exception: " << e.what() << "\n"; }

    try { cout << "getElement(length): " << li.getElement(li.getLength()) << "\n"; }
    catch (const exception& e) { cout << "Caught exception: " << e.what() << "\n"; }

    cout << "\nreplace() valid cases:\n";
    cout << "replace(2, 300)\n";
    li.replace(2, 300);
    cout << li;

    cout << "replace(last, 999)\n";
    li.replace(li.getLength() - 1, 999);
    cout << li;

    cout << "replace(0, 111) (head element):\n";
    try {
        li.replace(0, 111);
        cout << li;
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << "\n";
    }

    cout << "\nreplace() invalid cases:\n";
    try { li.replace(-1, 123); }
    catch (const exception& e) { cout << "Caught exception: " << e.what() << "\n"; }

    try { li.replace(li.getLength(), 123); }
    catch (const exception& e) { cout << "Caught exception: " << e.what() << "\n"; }

    cout << "\nClearing non-empty list:\n";
    li.clear();
    cout << "After clear -> length: " << li.getLength()
         << ", isEmpty(): " << li.isEmpty() << "\n";
    cout << li << "\n";

    cout << "Appending after clear: 7, 8\n";
    li.append(7); li.append(8);
    cout << li;
    cout << "Length: " << li.getLength() << "\n\n";

    cout << "==================== STRING LIST ====================\n";
    LinkedList<string> ls;

    cout << "Empty string list:\n";
    cout << ls << "\n";

    cout << "Appending: \"CS\", \"20\", \"LinkedList\"\n";
    ls.append("CS"); ls.append("20"); ls.append("LinkedList");
    cout << ls;
    cout << "Length: " << ls.getLength() << "\n";

    cout << "getElement(1): " << ls.getElement(1) << "\n";

    cout << "getElement(3) (should throw):\n";
    try { cout << ls.getElement(3) << "\n"; }
    catch (const exception& e) { cout << "Caught exception: " << e.what() << "\n"; }

    cout << "replace(1, \"is\"):\n";
    ls.replace(1, "is");
    cout << ls;

    cout << "clear() string list:\n";
    ls.clear();
    cout << "After clear -> length: " << ls.getLength()
         << ", isEmpty(): " << ls.isEmpty() << "\n";
    cout << ls << "\n\n";

    cout << "==================== DOUBLE LIST ====================\n";
    LinkedList<double> ld;

    cout << "Empty double list:\n";
    cout << ld << "\n";

    cout << "Appending: 3.14, 2.71, -0.5\n";
    ld.append(3.14); ld.append(2.71); ld.append(-0.5);
    cout << ld;
    cout << "Length: " << ld.getLength() << "\n";

    cout << "getElement(0): " << ld.getElement(0) << "\n";
    cout << "getElement(2): " << ld.getElement(2) << "\n";

    cout << "replace(1, 9.99):\n";
    ld.replace(1, 9.99);
    cout << ld;

    cout << "getElement(-1) (should throw):\n";
    try { cout << ld.getElement(-1) << "\n"; }
    catch (const exception& e) { cout << "Caught exception: " << e.what() << "\n"; }

    cout << "clear() double list:\n";
    ld.clear();
    cout << "After clear -> length: " << ld.getLength()
         << ", isEmpty(): " << ld.isEmpty() << "\n";
    cout << ld << "\n\n";

    cout << "==================== CHAR LIST ====================\n";
    LinkedList<char> lc;

    cout << "Empty char list:\n";
    cout << lc << "\n";

    cout << "Appending: 'a', 'Z', '!'\n";
    lc.append('a'); lc.append('Z'); lc.append('!');
    cout << lc;
    cout << "Length: " << lc.getLength() << "\n";

    cout << "getElement(1): " << lc.getElement(1) << "\n";
    cout << "replace(2, '?'):\n";
    lc.replace(2, '?');
    cout << lc;

    cout << "replace(100, 'x') (should throw):\n";
    try { lc.replace(100, 'x'); }
    catch (const exception& e) { cout << "Caught exception: " << e.what() << "\n"; }

    cout << "clear() char list:\n";
    lc.clear();
    cout << "After clear -> length: " << lc.getLength()
         << ", isEmpty(): " << lc.isEmpty() << "\n";
    cout << lc << "\n\n";

    cout << "==================== BOOL LIST ====================\n";
    LinkedList<bool> lb;

    cout << "Empty bool list:\n";
    cout << lb << "\n";

    cout << "Appending: true, false, true\n";
    lb.append(true); lb.append(false); lb.append(true);
    cout << lb;
    cout << "Length: " << lb.getLength() << "\n";

    cout << "getElement(0): " << boolalpha << lb.getElement(0) << "\n";
    cout << "getElement(1): " << boolalpha << lb.getElement(1) << "\n";

    cout << "replace(1, true):\n";
    lb.replace(1, true);
    cout << lb;

    cout << "getElement(3) (should throw):\n";
    try { cout << lb.getElement(3) << "\n"; }
    catch (const exception& e) { cout << "Caught exception: " << e.what() << "\n"; }

    cout << "clear() bool list:\n";
    lb.clear();
    cout << "After clear -> length: " << lb.getLength()
         << ", isEmpty(): " << lb.isEmpty() << "\n";
    cout << lb << "\n\n";
    return 0;
}
