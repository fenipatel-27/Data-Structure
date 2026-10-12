#include <iostream>
#include <string>
using namespace std;
struct Product {
    int id;
    string name;
    float price;
    int stock;
    Product* next;
};
struct CartItem {
    int id;
    string name;
    float price;
    int quantity;
    CartItem* next;
};
void addProduct(Product*& head) {
    Product* newProduct = new Product;
    cout << "\nEnter Product ID: ";
    cin >> newProduct->id;
    cout << "Enter Product Name: ";
    cin >> newProduct->name;
    cout << "Enter Price: ";
    cin >> newProduct->price;
    cout << "Enter Stock: ";
    cin >> newProduct->stock;
    newProduct->next = nullptr;
    if (head == nullptr) {
        head = newProduct;
    }
    else {
        Product* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newProduct;
    }
    cout << "\nProduct added successfully!\n";
}
void displayProducts(Product* head) {
    if (head == nullptr) {
        cout << "\nNo products available.\n";
        return;
    }
    cout << "\n========== AVAILABLE PRODUCTS ==========\n";
    cout << "ID\tName\t\tPrice\tStock\n";
    Product* temp = head;
    while (temp != nullptr) {
        cout << temp->id << "\t"
             << temp->name << "\t\t"
             << temp->price << "\t"
             << temp->stock << endl;
        temp = temp->next;
    }
}
Product* searchProduct(Product* head, int id) {
    Product* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}
void deleteProduct(Product*& head) {
    int id;
    cout << "\nEnter Product ID to delete: ";
    cin >> id;
    if (head == nullptr) {
        cout << "Product list is empty.\n";
        return;
    }
    if (head->id == id) {
        Product* temp = head;
        head = head->next;
        delete temp;
        cout << "Product deleted successfully!\n";
        return;
    }
    Product* temp = head;
    while (temp->next != nullptr &&
           temp->next->id != id) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Product not found.\n";
    }
    else {
        Product* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Product deleted successfully!\n";
    }
}
void addToCart(Product* products, CartItem*& cart) {
    int id, quantity;
    cout << "\nEnter Product ID: ";
    cin >> id;
    Product* product = searchProduct(products, id);
    if (product == nullptr) {
        cout << "Product not found.\n";
        return;
    }
    cout << "Enter Quantity: ";
    cin >> quantity;
    if (quantity <= 0 || quantity > product->stock) {
        cout << "Invalid quantity or insufficient stock.\n";
        return;
    }
    CartItem* temp = cart;
    while (temp != nullptr) {
        if (temp->id == id) {
            temp->quantity += quantity;
            product->stock -= quantity;
            cout << "Quantity updated in cart.\n";
            return;
        }
        temp = temp->next;
    }
    CartItem* newItem = new CartItem;
    newItem->id = product->id;
    newItem->name = product->name;
    newItem->price = product->price;
    newItem->quantity = quantity;
    newItem->next = nullptr;
    if (cart == nullptr) {
        cart = newItem;
    }
    else {
        temp = cart;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
    product->stock -= quantity;
    cout << "Product added to cart!\n";
}
void displayCart(CartItem* cart) {
    if (cart == nullptr) {
        cout << "\nYour cart is empty.\n";
        return;
    }
    float total = 0;
    cout << "\n============== YOUR CART ==============\n";
    cout << "ID\tName\t\tPrice\tQty\tAmount\n";
    CartItem* temp = cart;
    while (temp != nullptr) {
        float amount = temp->price * temp->quantity;
        total += amount;
        cout << temp->id << "\t"
             << temp->name << "\t\t"
             << temp->price << "\t"
             << temp->quantity << "\t"
             << amount << endl;
        temp = temp->next;
    }
    cout << "----------------------------------------\n";
    cout << "Total: Rs. " << total << endl;
}
void removeFromCart(CartItem*& cart, Product* products) {
    int id;
    cout << "\nEnter Product ID to remove: ";
    cin >> id;
    if (cart == nullptr) {
        cout << "Cart is empty.\n";
        return;
    }
    if (cart->id == id) {
        CartItem* del = cart;
        Product* product = searchProduct(products, id);
        if (product != nullptr) {
            product->stock += del->quantity;
        }
        cart = cart->next;
        delete del;
        cout << "Product removed from cart.\n";
        return;
    }
    CartItem* temp = cart;
    while (temp->next != nullptr &&
           temp->next->id != id) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Product not found in cart.\n";
    }
    else {
        CartItem* del = temp->next;
        Product* product = searchProduct(products, id);
        if (product != nullptr) {
            product->stock += del->quantity;
        }
        temp->next = del->next;
        delete del;
        cout << "Product removed from cart.\n";
    }
}
void updateQuantity(CartItem* cart, Product* products) {
    int id, newQuantity;
    cout << "\nEnter Product ID: ";
    cin >> id;
    CartItem* item = cart;
    while (item != nullptr && item->id != id) {
        item = item->next;
    }
    if (item == nullptr) {
        cout << "Product not found in cart.\n";
        return;
    }
    Product* product = searchProduct(products, id);
    cout << "Current Quantity: " << item->quantity << endl;
    cout << "Enter New Quantity: ";
    cin >> newQuantity;
    if (newQuantity <= 0) {
        cout << "Invalid quantity.\n";
        return;
    }
    int difference = newQuantity - item->quantity;
    if (difference > product->stock) {
        cout << "Not enough stock available.\n";
        return;
    }
    product->stock -= difference;
    item->quantity = newQuantity;
    cout << "Quantity updated successfully!\n";
}
void generateBill(CartItem* cart) {
    if (cart == nullptr) {
        cout << "\nCart is empty. Cannot generate bill.\n";
        return;
    }
    float total = 0;
    cout << "\n========================================\n";
    cout << "              FINAL BILL\n";
    cout << "========================================\n";
    CartItem* temp = cart;
    while (temp != nullptr) {
        float amount = temp->price * temp->quantity;
        cout << temp->name
             << " x " << temp->quantity
             << " = Rs. " << amount << endl;
        total += amount;
        temp = temp->next;
    }
    cout << "----------------------------------------\n";
    cout << "Total Amount: Rs. " << total << endl;
    cout << "========================================\n";
    cout << "       Thank you for shopping!\n";
    cout << "========================================\n";
}
int main() {
    Product* products = nullptr;
    CartItem* cart = nullptr;
    int choice;
    Product* p1 = new Product{101, "Laptop", 50000, 5, nullptr};
    Product* p2 = new Product{102, "Mouse", 800, 20, nullptr};
    Product* p3 = new Product{103, "Keyboard", 1500, 10, nullptr};
    Product* p4 = new Product{104, "Headphones", 2000, 8, nullptr};
    products = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    do {
        cout << "\n\n========================================";
        cout << "\n       ONLINE SHOPPING CART SYSTEM";
        cout << "\n========================================";
        cout << "\n1. View Products";
        cout << "\n2. Add New Product";
        cout << "\n3. Delete Product";
        cout << "\n4. Search Product";
        cout << "\n5. Add Product to Cart";
        cout << "\n6. Remove Product from Cart";
        cout << "\n7. Update Cart Quantity";
        cout << "\n8. View Cart";
        cout << "\n9. Generate Bill";
        cout << "\n10. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            displayProducts(products);
            break;
        case 2:
            addProduct(products);
            break;
        case 3:
            deleteProduct(products);
            break;
        case 4: {
            int id;
            cout << "\nEnter Product ID: ";
            cin >> id;
            Product* product = searchProduct(products, id);
            if (product != nullptr) {
                cout << "\nProduct Found!\n";
                cout << "Name: " << product->name << endl;
                cout << "Price: Rs. " << product->price << endl;
                cout << "Stock: " << product->stock << endl;
            }
            else {
                cout << "Product not found.\n";
            }
            break;
        }
        case 5:
            addToCart(products, cart);
            break;
        case 6:
            removeFromCart(cart, products);
            break;
        case 7:
            updateQuantity(cart, products);
            break;
        case 8:
            displayCart(cart);
            break;
        case 9:
            generateBill(cart);
            break;
        case 10:
            cout << "\nThank you!\n";
            break;
        default:
            cout << "\nInvalid choice!\n";
        }
    } while (choice != 10);
    return 0;
}