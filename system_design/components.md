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

## CDN (Content Delivery Network)

#### Some websites load almost instantly despite heavy images, videos, or assets. CDNs make this possible. A CDN is a distributed network of servers delivering content quickly and efficiently by storing cached copies of static assets closer to users' locations.

CDNs solve
- high latency (users far from servers experience delays as requests and responses travel). 
- bandwidth overload (traffic surges overwhelm origin servers causing slowdowns or crashes). 
- global scalability (hosting assets in one location makes serving worldwide users difficult without performance issues).

### How CDNs Work

When a user visits your site, their request routes to the nearest CDN server. If the requested file is cached there (cache hit), the server delivers it immediately. If not cached (cache miss), the CDN fetches it from the origin server, caches it locally, then serves it to the user.

### Common Implementations
- Cloudflare is popular for ease of use and strong security. It offers a global network with low latency, built-in DDoS protection and Web Application Firewall.
- AWS CloudFront is Amazon's fully managed CDN integrated with AWS services. It provides seamless integration with AWS storage (S3) and compute (Lambda) and supports dynamic and static content delivery.
- Akamai is one of the oldest and most robust CDNs, typically used by enterprises. It offers an industry-leading global server network for ultra-low latency and advanced customization and analytics tools.

## Message Queues

Distributed systems need reliable communication between services while sending and processing large task or data volumes.

directly connecting services creates: 
- tight coupling (services become dependent, making systems harder to scale or modify).
-  overloading (one service generating more tasks than another can handle leads to failures or bottlenecks). 
- Task management issues (without tracking, it's easy to lose or duplicate data when services crash or restart).

An e-commerce system demonstrates this. The order service must notify inventory, payment, and shipping services. If all interactions happen directly, any failure or delay breaks the entire system.

#### Message queues solve these problems by acting as intermediaries. Services send messages without worrying whether receiving services are ready to process them. This makes systems more reliable, decoupled, and scalable.

### How Message Queues Work
1. **Producers** send messages (tasks or data) to the queue. A producer could be any service generating work, like an order service in e-commerce.
2. The queue temporarily stores messages until processed. Messages store in arrival order.
3. **Consumers** retrieve messages from the queue and process them. A payment service might consume a message about a new order to initiate payment.

This pattern works because it decouples producers and consumers. Producers don't wait for consumers to process tasks. They send messages and move on. Consumers process messages at their own pace, making systems more resilient to load spikes or partial failures.

Interviews expect you to explain: 
- **acknowledgements** (consumers send acknowledgment after successfully processing messages; without acknowledgment, messages can be re-delivered ensuring reliability). 
- **dead letter queues** (messages failing repeated processing send to separate queues for debugging or manual handling). 
- **message ordering** (some queues ensure FIFO delivery while others allow out-of-order processing for higher throughput).

### Common Implementations

- **Point-to-Point (P2P)** queues have a single consumer processing each message. Use for processing user orders in e-commerce. Tools: RabbitMQ, AWS SQS.

- **Publisher-Subscriber (Pub/Sub)** queues allow multiple consumers to subscribe to topics and receive messages. Use for sending order updates to inventory, payment, and shipping services simultaneously. Tools: Apache Kafka, Google Pub/Sub.

- **RabbitMQ** is a widely-used message broker supporting both P2P and Pub/Sub models. Use it for traditional queueing with complex routing and acknowledgment features.

- **Apache Kafka** is a distributed event streaming platform designed for high-throughput use cases. Use it for Pub/Sub scenarios and real-time analytics.

## API Gateway

Managing how clients interact with backends becomes critical in distributed systems using microservices. **APIs bridge clients (web browsers, mobile apps) to backend services**. 

API Gateways solve issues by acting as single entry points for all API requests. They route requests to appropriate services, handle cross-cutting concerns like authentication, and optimize performance with caching and rate limiting. Think of them as traffic cops directing and controlling request flow.

### How API Gateways Work

- Clients send API requests to the gateway instead of directly to backend services. The gateway inspects requests and determines which backend service to forward them to.
- While processing requests, the gateway performs authentication (ensures requests come from valid users or systems), rate limiting (caps request numbers in specific timeframes protecting backend services), caching (serves frequent requests from cache instead of hitting backend services reducing latency), and logging and monitoring (tracks request details for debugging or usage analytics).

**interviews may ask about authentication and authorization (how gateways handle tokens like OAuth or JWT ensuring secure access), rate limiting (preventing abuse or overload by capping request rates), and load balancing (distributing incoming requests across multiple instances optimizing performance and reliability).**