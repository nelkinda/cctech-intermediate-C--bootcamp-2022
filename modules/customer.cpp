// Option 1
class Customer {
    string name;
    string deliveryAddressName;
    string deliveryAddress1;
    string deliveryAddress2;
    string deliveryAddress3;
    string deliveryAddressCity;
    string deliveryAddressState;
    string deliveryAddressPin;
    string deliveryAddressCountry;
    string billingAddressName;
    string billingAddress1;
    string billingAddress2;
    string billingAddress3;
    string billingAddressCity;
    string billingAddressState;
    string billingAddressPin;
    string billingAddressCountry;
};

// Option 2
class Address {
    string name;
    string address1;
    string address2;
    string address3;
    string addressCity;
    string addressState;
    string addressPin;
    string addressCountry;
};

class Customer {
    string name;
    Address deliveryAddress;
    Address billingAddress;
};


// Not all code duplicates can be spotted through duplicate text.
// Look at the following example of duplicate code:

for (int i = 0; i < items.size(); i++) {
    items[i].add();
}
for (auto item : items) {
    item.add();
}
