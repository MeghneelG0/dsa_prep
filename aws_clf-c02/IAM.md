### IAM Users & Groups

- IAM = Identity and Access Management, Global service. 
- Root account created by default, shouldn’t be used or shared.
- Users are people within your organization, and can be grouped
- Groups only contain users, not other groups.
- Users don’t have to belong to a group, and user can belong to multiple groups. 
![alt text](image.png)

### IAM: Permissions
- Users or Groups can be assigned JSON documents called policies. 
- These policies define thepermissions of the users. 
- In AWS you apply the least privilege principle: don’t give more permissions than a user needs. 

### IAM Policies Structure

Consists of
- Version: policy language version, always include “2012-10-17”
- Id: an identifier for the policy (optional)
- Statement: one or more individual statements (required)

Statements consists of
- Sid: an identifier for the statement (optional)
- Effect: whether the statement allows or denies access(Allow, Deny)
- Principal: account/user/role to which this policy applied to
- Action: list of actions this policy allows or denies
- Resource: list of resources to which the actions applied to• Condition: conditions for when this policy is in effect(optional).
