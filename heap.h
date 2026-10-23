#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap {
 public:
  /**
   * @brief Construct a new Heap object
   *
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m = 2, PComparator c = PComparator());

  /**
   * @brief Destroy the Heap object
   *
   */
  ~Heap();

  /**
   * @brief Push an item to the heap
   *
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   *
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const& top() const;

  /**
   * @brief Remove the top priority item
   *
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   *
   */
  bool empty() const;

  /**
   * @brief Returns size of the heap
   *
   */
  size_t size() const;

 private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> elems_;
  int m_;
  PComparator c_;

  void trickleUp(size_t index);
  void trickleDown(size_t index);
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), c_(c) {
  if (m < 2) {
    throw std::invalid_argument("Heap arity must be at least 2");
  }
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return elems_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return elems_.size();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  elems_.push_back(item);
  trickleUp(elems_.size() - 1);
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(size_t index) {
  while (index > 0) {
    size_t parent = (index - 1) / m_;

    if (c_(elems_[index], elems_[parent])) {
      T temp = elems_[index];
      elems_[index] = elems_[parent];
      elems_[parent] = temp;

      index = parent;
    } else {
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(size_t index) {
  while (true) {
    size_t best = index;
    size_t firstChild = m_ * index + 1;

    for (int i = 0; i < m_; i++) {
      size_t child = firstChild + i;

      if (child >= elems_.size()) {
        break;
      }

      if (c_(elems_[child], elems_[best])) {
        best = child;
      }
    }

    if (best == index) {
      break;
    }

    T temp = elems_[index];
    elems_[index] = elems_[best];
    elems_[best] = temp;

    index = best;
  }
}
// We will start top() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
T const& Heap<T, PComparator>::top() const {
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if (empty()) {
    // ================================
    // throw the appropriate exception
    // ================================

    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return elems_[0];
}

// We will start pop() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop() {
  if (empty()) {
    // ================================
    // throw the appropriate exception
    // ================================

    throw std::underflow_error("Heap is empty");
  }

  if (elems_.size() == 1) {
    elems_.pop_back();
    return;
  }

  elems_[0] = elems_.back();
  elems_.pop_back();

  trickleDown(0);
}

#endif
