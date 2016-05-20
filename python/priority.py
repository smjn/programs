#! /usr/bin/env python
import Queue
import heapq

heap = []
heap.extend([4,8,0])
heapq.heapify(heap)

print heap
