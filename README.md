# push_swap

Sorts a list of integers using two stacks and a limited set of operations, while using as few operations as possible. Written at 42 Kuala Lumpur (2024).

```sh
./push_swap 3 2 5 1 4
```
It prints the list of operations that sorts the input: `sa` `sb` `ss` `pa` `pb` `ra` `rb` `rr` `rra` `rrb` `rrr`.

## Approach
- The stacks are linked lists
- **3 numbers:** hard-coded optimal sort. **5 numbers:** push the two smallest to stack B, sort three, push them back
- **Larger inputs:** cost-based insertion. For every node, work out its target position in the other stack and how many rotations it would take to get there, combining moves with `rr`/`rrr` where possible. Then move the cheapest node each turn.
- Rejects bad input: non-integers, duplicates and values outside int range

## Build
```sh
make
```
