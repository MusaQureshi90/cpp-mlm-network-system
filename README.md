# 🌐 Multi-Level Marketing (MLM) Network & Ledger System

A high-performance command-line application developed in **C++** that simulates an incentive-driven **Multi-Level Marketing (MLM)** and referral hierarchy network. Designed as an algorithmic study in network topologies, balanced trees, and transaction audit systems.

---

## 🚀 Key Features

* **Hierarchical Downline Architecture:** Models direct user-to-sponsor downline structures through key-value mappings.
* **Instant Incentive Engine:** Real-time commission allocation crediting upstream referrers upon new member onboarding.
* **Double-Entry Transaction Ledger:** Persistent in-memory transaction audit logs tracking credits, bonuses, and debits per user.
* **Balance & Liquidity Verification:** Built-in safeguards verifying wallet balance before committing withdrawal transactions.

---

## 📊 Algorithmic & Complexity Analysis

| Operation | Target Data Structure | Time Complexity (Average) | Time Complexity (Worst-Case) |
| :--- | :--- | :--- | :--- |
| **User Registration** | `std::map` (Self-Balancing BST) | $\mathcal{O}(\log N)$ | $\mathcal{O}(\log N)$ |
| **Referral Verification** | Balanced Tree Lookup | $\mathcal{O}(\log N)$ | $\mathcal{O}(\log N)$ |
| **Commission Update** | Node Value Mutation | $\mathcal{O}(\log N)$ | $\mathcal{O}(\log N)$ |
| **Withdrawal Processing** | In-Place Balance Check | $\mathcal{O}(\log N)$ | $\mathcal{O}(\log N)$ |
| **Transaction History** | `std::vector` Sequential Scan | $\mathcal{O}(M)$ | $\mathcal{O}(M)$ |
| **Directory Traversal** | Full In-Order Traversal | $\mathcal{O}(N)$ | $\mathcal{O}(N)$ |

*where $N$ is the number of active users, and $M$ is the number of transactions per user.*

---

## 🛠️ Built With

* **Language:** C++ (Standard C++11 / C++17)
* **Paradigm:** Object-Oriented Programming (OOP) & Data Structure Optimization
* **Core STL Modules:** `std::map`, `std::vector`, `std::string`
* **Compiler Support:** GCC / MinGW / Clang / MSVC

---

## 💻 Build & Execution

### 1. Compile with GCC
```bash
g++ -std=c++11 -O2 main.cpp -o MLMSystem
```

### 2. Run Executable
```bash
./MLMSystem
```

---

## 👤 Author
**Muhammad Musa Qureshi**
* **GitHub:** [@MusaQureshi90](https://github.com/MusaQureshi90)
* **LinkedIn:** [Musa Qureshi](https://www.linkedin.com/in/musaqureshi90/)
