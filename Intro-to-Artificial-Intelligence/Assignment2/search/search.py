# search.py
# ---------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in searchAgents.py).
"""

import util

class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
        """
        Returns the start state for the search problem.
        """
        util.raiseNotDefined()

    def isGoalState(self, state):
        """
          state: Search state

        Returns True if and only if the state is a valid goal state.
        """
        util.raiseNotDefined()

    def getSuccessors(self, state):
        """
          state: Search state

        For a given state, this should return a list of triples, (successor,
        action, stepCost), where 'successor' is a successor to the current
        state, 'action' is the action required to get there, and 'stepCost' is
        the incremental cost of expanding to that successor.
        """
        util.raiseNotDefined()

    def getCostOfActions(self, actions):
        """
         actions: A list of actions to take

        This method returns the total cost of a particular sequence of actions.
        The sequence must be composed of legal moves.
        """
        util.raiseNotDefined()


def tinyMazeSearch(problem):
    """
    Returns a sequence of moves that solves tinyMaze.  For any other maze, the
    sequence of moves will be incorrect, so only use this for tinyMaze.
    """
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    return  [s, s, w, s, w, w, s, w]

def depthFirstSearch(problem):
    """
    Search the deepest nodes in the search tree first.

    Your search algorithm needs to return a list of actions that reaches the
    goal. Make sure to implement a graph search algorithm.

    To get started, you might want to try some of these simple commands to
    understand the search problem that is being passed in:

    print "Start:", problem.getStartState()
    print "Is the start a goal?", problem.isGoalState(problem.getStartState())
    print "Start's successors:", problem.getSuccessors(problem.getStartState())
    """
    "*** YOUR CODE HERE ***"
  #  util.raiseNotDefined()
   
    ds = util.Stack()  
    visits = []
    ds.push((problem.getStartState(),[], [])) # It pushes the start pacman state into it with 2 empty arrays for direction of each step and another to add to direction array for a path to goal state  
    d = 1
    while d:    
      a,b,c = ds.pop()
      if(problem.isGoalState(a)): # In the loop, it is checked whether the current state is a goal state
          return c
      if a in visits: # checks if the current state has been visited or not
        continue
      else:  
        visits.append(a) # adds the state to the array of visited nodes
        s = problem.getSuccessors(a)
        for m1,m2,m3 in s:
          if m1 in visits: # checks for the successor state whether it is in visited nodes array or not
            continue
          else:  
            ds.push((m1, m2, c + [m2])) # Pushes the current state, action and the direction to the stack 
      d = not ds.isEmpty()      

def breadthFirstSearch(problem):
    """Search the shallowest nodes in the search tree first."""
    "*** YOUR CODE HERE ***"
 #  util.raiseNotDefined()  
    # works the same way as DFS, except that it uses Queue as the data strcuture for search implementation
    bs = util.Queue()
    visits = []
    bs.push((problem.getStartState(),[], []))
    
    d = 1
    while d:
      a,b,c = bs.pop()
      if(problem.isGoalState(a)):
          return c
      if(a in visits):
        continue
      else:  
        visits.append(a) 
        s = problem.getSuccessors(a)
        for m1,m2,m3 in s:
          if m1 in visits:
            continue
          else:  
            bs.push((m1, m2, c + [m2]))
      d = not bs.isEmpty()          

  
 
    
def uniformCostSearch(problem):
    """Search the node of least total cost first."""
    "*** YOUR CODE HERE ***"
   # util.raiseNotDefined()
    
    # Works the same as BFS and DFS, except that it also takes the cost into account in each successive state

    visits = []
    uc = util.PriorityQueue() 
    uc.push((problem.getStartState(), []) ,0) # pushes the state, action and cost of each successive state into the Priority Queue
    
    d = 1
    while d:
        a, b = uc.pop() # Pops out the current state with cost and action with cost
        if problem.isGoalState(a):
            return b
        if a in visits:
            continue
        else:
            visits.append(a)    
            s = problem.getSuccessors(a) 
            for m1,m2,m3 in s: # loops runs for the successive state,action and each step cost 
                if m1 in visits:
                    continue
                else:  
                    uc.push((m1, b + [m2]), problem.getCostOfActions(b + [m2])) 
        d = not uc.isEmpty()            

    
def nullHeuristic(state, problem=None):
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0

def aStarSearch(problem, heuristic=nullHeuristic):
    """Search the node that has the lowest combined cost and heuristic first."""
    "*** YOUR CODE HERE ***"
#    util.raiseNotDefined()

    visits = []
    aS = util.PriorityQueue()
    aS.push((problem.getStartState(), []), nullHeuristic(problem.getStartState(), problem)) # with the current state as in bfs,dfs it also adds the heuristics start state and problem into Priority Queue

    d = 1
    while d:
        a, b = aS.pop() # Pops out the current state and a direction array
      #  print b
        if problem.isGoalState(a):
            return b
        if a in visits:
            continue
        else:
            visits.append(a)    
            s = problem.getSuccessors(a)
            for m1,m2,m3 in s: # loops runs for the successive state,action and each step cost 
                if m1 in visits:
                    continue
                else:    
                    aS.push((m1, b + [m2]), problem.getCostOfActions(b + [m2]) + heuristic(m1, problem))
        d = not aS.isEmpty()         



  

# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch
