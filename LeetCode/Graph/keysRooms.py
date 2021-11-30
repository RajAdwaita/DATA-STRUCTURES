def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
    q = [p for p in rooms[0]]
    visited = set([0])
    while q:
        curr = q.pop()
        visited.add(curr)
        next_keys = rooms[curr]
        q += [r for r in next_keys if r not in visited]
        return True if len(visited) == len(rooms) else False
