# Interview Step-by-Step
Success in system design interviews requires structured approaches. 
This section demonstrates the process by solving Design Twitter, a popular system design problem.

### Functional Requirements
Defining core functional requirements is the first step. This stage takes only a few minutes.
- Think of requirements as "Users can do...". For Spotify, users can listen to songs, make playlists, and upload their own songs. These are core functional requirements.
- For Twitter, users can post tweets, view individual tweets, view feeds, follow other users, like tweets, and comment on tweets.

### Non-Functional Requirements

After defining functional requirements, define non-functional requirements.
- Functional requirements outline what users can do. Non-functional requirements outline what systems should do or have to support functional requirements.

Common considerations include: 
- performance (response speed, acceptable latency thresholds)
-  availability (system accessibility, uptime through redundancy and monitoring)
- scalability (handling increasing users, data, or traffic without performance degradation through vertical or horizontal scaling)
- reliability (handling failures through fault tolerance)
- consistency (data accuracy across all users and operations), durability (safe data storage preventing loss from hardware failures or power outages)
- security (protection against unauthorized access or attacks)

For Twitter, we need low latency (users post tweets and view feeds quickly for smooth experiences), high availability (maintain near 100% uptime ensuring platform accessibility), scalability (support horizontal scaling handling user base growth and increased traffic), and data durability (store tweets, likes, and comments in distributed, fault-tolerant systems preventing data loss).

### API Design