# SSH mastery
## keys
public key and private key can be encryt and decrepyt messages using both.
### private key
used to read message from server holdeing public key.
### public key
used to authenticate user to see whether he has the private key.
### temporary key pair
server and client will generate temporary key-pair to during the session.

## configruation directory

```=
/etc/ssh
```
* it contains all the auto-generated key pairs.

### system wide configuration file

```=
/etc/ssh/ssh_config
```
* default configuration file for ssh **client**

```=
/etc/ssh/sshd_config
```
* default configuration file for ssh **server**

### key pairs

```=
/etc/ssh/ssh_host_*_key
```
* this is the private key
```=
/etc/ssh/ssh_host_*_key.pub
```
* this is the public key
* `*` represents different encyption algorithm

