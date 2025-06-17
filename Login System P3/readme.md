# 🔐 Login & Registration System in C

A simple, secure login and registration system written in C using file-based user data storage. Designed as part of my "Basic-to-Advanced C Projects" learning path.

---

## 📜 Features

- Register a new user with username & password  
- Login with existing credentials  
- Input sanitisation using `fgets()`  
- File-based data storage in `user_details.txt`  
- Clear screen function for better UX (`cls` or `clear`)  
- Struct-based user data management  
- Simple and extendable design  

---

## 🛠️ Compilation & Execution

```bash
gcc login_register.c -o login_system
./login_system
```
---

## ✅ Sample Output

1.Login
2.Register
3.Exit
Enter your option: 1

[*]--- THIS LOGING PAGE ---[*]

Enter a password: mypass123
Enter a username: nizath
Access Granted!

---

## ⚠️ Security Notes

- Passwords are stored in plaintext (not safe for real-world use)
- Future plans: Add hashing (e.g., SHA-256), password masking, and multi-user handling

---

## 🏗️ Future Improvements

- 🔒 Add password hashing (e.g., SHA256)
- 👁️ Mask password input with *
- 📁 Improve file management and error handling
- 📈 Log login attempts

