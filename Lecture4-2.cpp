// #include <iostream>
// #include <vector>
// #include <list>

// using namespace std;

// // Hàm băm h(i) = (2i + 5) mod 11
// int hashFunction(int i) {
//     return (2 * i + 5) % 11;
// }

// int main() {
//     int keys[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};
//     int hashTableSize = 11;

//     // Phương pháp chuỗi (Chaining)
//     vector<list<int>> hashTableChaining(hashTableSize);

//     for (int key : keys) {
//         int hashValue = hashFunction(key);
//         hashTableChaining[hashValue].push_back(key);
//     }

//     cout << "a) Xử lý va chạm bằng phương pháp chuỗi (Chaining):\n";
//     for (int i = 0; i < hashTableSize; i++) {
//         cout << i << ": ";
//         for (int key : hashTableChaining[i]) {
//             cout << key << " -> ";
//         }
//         cout << "nullptr" << endl;
//     }

//     // Đặt lại bảng băm và sử dụng phương pháp tìm kiếm tuyến tính (Linear Probing)
//     vector<int> hashTableLinearProbing(hashTableSize, -1); // -1 là thùng trống

//     for (int key : keys) {
//         int hashValue = hashFunction(key);
//         while (hashTableLinearProbing[hashValue] != -1) {
//             // Tìm thùng trống tiếp theo
//             hashValue = (hashValue + 1) % hashTableSize;
//         }
//         hashTableLinearProbing[hashValue] = key;
//     }

//     cout << "\nb) Xử lý va chạm bằng phương pháp tìm kiếm tuyến tính (Linear Probing):\n";
//     for (int i = 0; i < hashTableSize; i++) {
//         cout << i << ": ";
//         if (hashTableLinearProbing[i] != -1) {
//             cout << hashTableLinearProbing[i];
//         }
//         cout << endl;
//     }

//     return 0;
// }
