<h1>Overview</h1>
This repo represents the implementation of a basic blockchain from scratch, and entirely in C, as part of the Holberton Training Program. 

  ![image](https://github.com/abir9hassini/emsi-blockchain/assets/40744191/e1b0330e-df78-468b-941d-221090e973bf)


![OS Linux](https://img.shields.io/badge/OS-Linux-blue.svg)
![distro Ubuntu](https://img.shields.io/badge/distro-Ubuntu-orange.svg)
![Programming language C](https://img.shields.io/badge/technology-C-green.svg)
![OpenSSL](https://img.shields.io/badge/toolkit-OpenSSL-brown.svg)
![Crypto](https://img.shields.io/badge/discipline-Crypto-yellow.svg)  


<h1>Topics</h1>
<ul>
  <li>What is a Blockchain?</li>
  <li> 0x00. Blockchain - Crypto</li>
  <li> 0x01. Blockchain - Data structures concepts</li>
  <li> 0x02. Blockchain - Block mining</li>
</ul>


<h1> What is a Blockchain?</h1>
A blockchain is essentially a digital ledger of transactions that is duplicated and distributed across the entire network of computer systems on the blockchain, each block contains data and a reference to the previous one in the list. Visit this <a href="https://medium.com/@hassini.abir/what-is-a-blockchain-and-why-it-is-so-secure-53a6d565798c">blog </a> to learn more about it.

<h1>0x00. Blockchain - Crypto</h1>
  <h2>Tasks</h2>
    <li>"0. SHA256" :Function that computes the hash of a sequence of bytes</li>
    <li>"1. EC_KEY creation" : Function that creates a new EC key pair</li>
    <li>"2. EC_KEY to public key": Function that extracts the public key from an EC_KEY opaque structure</li>
    <li>"3. EC_KEY from public key": function that creates an EC_KEY structure given a public key</li>
    <li>"4. EC_KEY - Save to file": function that saves an existing EC key pair on the disk.</li>
    <li>"5. EC_KEY - Load from file": function that loads an EC key pair from the disk</li>
    <li>"6. Signature": Implementing a function that signs a given set of bytes, using a given EC_KEY private key</li>
    <li>"7. Signature verification": Implementing a function that verifies the signature of a given set of bytes, using a given EC_KEY public key</li>
    <li>8. Library: Creation of a Makefile that compiles all the previous functions and archives them into a static library for future use.</li>

<h1>0x01. Blockchain - Data structures concepts</h1>
  <h2>Tasks</h2>
    <li>"0. Create Blockchain":Write a function that creates a Blockchain structure, and initializes it</li>
    <li>"1. Create Block":Write a function that creates a Block structure and initializes it. </li>
    <li>"2. Delete Block": Write a function that deletes an existing Block</li>
    <li>"3. Delete Blockchain": Write a function that deletes an existing Blockchain, along with all the Blocks it contains/li>
    <li>"4. Hash Block": Write a function that computes the hash of a Block</li>
    <li>"5. Save Blockchain": Write a function that serializes a Blockchain into a file</li>
    <li>"6. Load Blockchain": Write a function that deserializes a Blockchain from a file</li>
    <li>"7. Block validity": Write a function that verifies that a Block is valid</li>
    
<h1>0x02. Blockchain - Block mining</h1>
  <h2>Tasks</h2>
      <li>"0. Proof of work": Write a function that checks whether a given hash matches a given difficulty</li>
      <li>"1. Block is valid v0.2": check if a Block’s hash matches its difficulty</li>
      <li>"2. Block mining": Write a function that mines a Block in order to insert it in the Blockchain</li>
      <li>"3. Adjust difficulty": Write a function that computes the difficulty to assign to a potential next Block in the Blockchain.</li>

    
<h1>Requirements</h1>
  <ul>
    <li> <a href="https://ubuntu.com/download/desktop">Ubuntu 14.04 LTS</a></li>
    <li> <a href="https://help.ubuntu.com/community/OpenSSL#Practical_OpenSSL_Usage">OpenSSL library </a></li>
      <li><a href="https://www.vagrantup.com/">Vagrant</a></li>
      <li><a href="https://www.virtualbox.org/wiki/Downloads">VirtualBox</a></li>
      <li>C programs that will be compiled with gcc and some APIs to create and manipulate linked-lists.</li>
    </ul>
<h1>References</h1>
<ul>
  <li>https://help.ubuntu.com/community/OpenSSL#Practical_OpenSSL_Usage</li>
  <li>https://medium.com/@hassini.abir/what-is-a-blockchain-and-why-it-is-so-secure-53a6d565798c</li>

</ul>
