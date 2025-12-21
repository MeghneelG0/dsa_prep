# MAIN COMPONENTS

#### System design interviews test your ability to assemble components correctly. Learn how each technology works and when to use it. That's the game.

## 1. Microservices

Services contain application code and business logic. You can structure applications as monoliths or microservices. Large-scale systems benefit from microservices.
#### i. Monolithic architecture 
- Monolithic architecture puts all functionality in one codebase running as a single process. 
- This works for small applications but breaks at scale. Any change requires redeploying everything. A bug in one component crashes the whole system. The codebase grows harder to understand. Different components can't scale independently.

#### ii. Microservices 
- Microservices break applications into smaller, independent services handling specific business functions.
- An e-commerce system might split into product catalog, shopping cart, user authentication, order processing, and payment processing services.

### How Microservices Work
Each service runs as its own process and deploys independently. Services communicate through well-defined APIs, typically REST or gRPC. Each service manages its own database, preventing direct coupling. Services scale independently based on specific load requirements.
- service discovery (how services find each other), data consistency across services, and fault isolation (containing failures to prevent cascading).

### Common Implementations

- Spring Boot :  is popular for Java microservices. It provides built-in support for REST APIs and service discovery with an extensive ecosystem. Use it for Java-based microservices requiring robust enterprise features.
- Node.js with Express : offers lightweight, fast development with a large npm package ecosystem. Use it for JavaScript or TypeScript microservices needing quick iteration.
- Go with Gin : delivers excellent performance and built-in concurrency support. Use it for microservices requiring high throughput and low latency.

## Data storage 
- SQL : consistent, referential, querying. 
- NoSQL : flexible, fast writes, horizontal scaling. 
- Object Storage : unstructured data: images, videos, backups, logs. Traditional storage solutions like file systems or databases struggle with the scalability and flexibility needed for massive datasets

CAP theorem : 
- C — Consistency
- A — Availability
- P — Partition tolerance
- SQL systems prioritize C + A

- NoSQL systems prioritize A + P 

## CACHING 

Fetching data from databases takes time and compute resources. Each request might only take milliseconds, but at scale with millions of users, this creates significant problems: high latency (slow responses frustrate users), reduced availability (request floods overwhelm databases leading to downtime), and poor efficiency (repeatedly fetching identical data wastes compute resources).

#### Many systems are high-read, low-write, Users spend most time reading content, rarely creating it. 

### How Caches Work

A request arrives. Before hitting the database or API, the system checks the cache. If data exists in the cache (cache hit), it serves immediately without bothering the database.

#### Interviews expect you to explain eviction policies (rules determining which data to remove when cache reaches capacity). Least Recently Used (LRU) removes least recently used items first. First In First Out (FIFO) removes items in order added. Least Frequently Used (LFU) removes least frequently used items first. 
1. invalidation strategies
-  Time-To-Live (TTL) removes data after preset expiration. 
- Event-Based Invalidation clears or updates cache when underlying data changes. 
- Manual Invalidation explicitly removes or refreshes cache entries.

2. write strategies 

- Write-Through writes to cache and database simultaneously, keeping them synchronized. 
- Write-Behind writes to cache first, then asynchronously to database, improving write performance. 
- Write-Around writes directly to database, adding to cache only when read, reducing cache pollution for infrequently accessed data.