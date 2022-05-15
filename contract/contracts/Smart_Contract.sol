# pragma solidity ^0.5.0;

contract buying {
    address[16] public customers;

    // Buying a product
    function buy(uint productId) public returns (uint) {
        require(productId >= 0 && productId <= 15);
            customers[productId] = msg.sender;
        return productId;
    }

    // Retrieving the customers
    function getCustomers() public view returns (address[16] memory) {
        return customers;
    }

}