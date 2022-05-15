pragma solidity ^0.5.0;

contract Adoption {
    address[16] public adopters;

    // Adopting a pet
function adopt(uint productId) public returns (uint) {
  require(productId >= 0 && productId <= 15);

  adopters[productId] = msg.sender;

  return productId;
}

}