# /usr/bin/env python2.7
# vim: set fileencoding=utf-8
"""
In a party of N people, only one person (the celebrity) is known to everyone.
Such a person may be present in the party.  If yes, they don't know anyone else
at the party.

We can only ask whether "does person-A know person-B":

    HasAcquaintance(A, B) returns True if A knows B, False otherwise.

Find the celebrity at the party (if they exist) in as few calls to
HasAcquaintance as possible.
"""


D_IS_THE_CELEBRITY = {
    'a': ('b', 'c', 'd'),
    'b': ('c', 'd'),
    'c': ('a', 'd'),
    'd': (),
    'e': ('b', 'd'),
}

NO_CELEBRITY = {
    'a': ('b', 'c', 'd'),
    'b': ('c', 'd'),
    'c': ('a', 'd'),
    'd': ('e'),
    'e': ('b', 'd'),
}


class _BaseSolution:
    def __init__(self, edges=None):
        self.edges = edges or {}
        self.has_acquaintance_counter = 0
        self.answer = None
        self._called = False

    def HasAcquaintance(self, A, B):
        """Returns True if A knows B."""
        self.has_acquaintance_counter += 1
        return B in self.edges.get(A, ())

    def Solve(self, people=None):
        if people is None:
            people = self.edges.keys()
        celebrity = self.findTheCelebrity(people)
        self.answer = celebrity
        return self.has_acquaintance_counter, self.answer

    def __str__(self):
        if not self._called:
            self.Solve()
        return '%s => %s (%d calls to HasAcquaintance)' % (
            self.__class__.__name__,
            self.answer,
            self.has_acquaintance_counter)

    def findTheCelebrity(self, people):
        """Return the name of the celebrity if they are at the party.

        Return None if there is no celebrity at the party.
        """
        return None


class NSquaredSolution(_BaseSolution):
    pass
def main():
    for test_case in (D_IS_THE_CELEBRITY, NO_CELEBRITY):
        print
        print test_case
        print NSquaredSolution(test_case)


if __name__ == '__main__':
    main()
