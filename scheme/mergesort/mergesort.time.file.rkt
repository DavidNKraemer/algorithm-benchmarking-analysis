#lang racket
;;; http://eecs.ceas.uc.edu/~franco/C511/html/Scheme/mergesrt.html
;;; -----------------------------------------------------------------
;;; Merge two lists of numbers which are already in increasing order

(define merge-lists
  (lambda (l1 l2)
    (if (null? l1)
        l2
        (if (null? l2)
            l1
            (if (< (car l1) (car l2))
                (cons (car l1) (merge-lists (cdr l1) l2))
                (cons (car l2) (merge-lists (cdr l2) l1)))))))

;;; -------------------------------------------------------------------
;;; Given list l, output those tokens of l which are in even positions

(define even-numbers
  (lambda (l)
    (if (null? l)
        '()
        (if (null? (cdr l))
            '()
            (cons (car (cdr l)) (even-numbers (cdr (cdr l))))))))

;;; -------------------------------------------------------------------
;;; Given list l, output those tokens of l which are in odd positions

(define odd-numbers
  (lambda (l)
    (if (null? l)
        '()
        (if (null? (cdr l))
            (list (car l))
            (cons (car l) (odd-numbers (cdr (cdr l))))))))

;;; ---------------------------------------------------------------------
;;; Use the procedures above to create a simple and efficient merge-sort

(define merge-sort
  (lambda (l)
    (if (null? l)
        l
        (if (null? (cdr l))
            l
            (merge-lists
             (merge-sort (odd-numbers l))
             (merge-sort (even-numbers l)))))))

(define mergesort-time
  (lambda (List)
    (let ([before (current-inexact-milliseconds)])
      (merge-sort List)
      (let ([after (current-inexact-milliseconds)])
        (- after before)))))

(define mergesort-time-file
  (lambda (input-file output-file)
    (mergesort-time '(2 3))
    ;everytime scheme runs a new procedure it takes longer 
    ;because of configuration
    (let kernel ([source (open-input-file input-file)]
                 [target (open-output-file output-file)])
      (let ([nextval (read source)])
        (cond 
          [(eof-object? nextval) 
           (close-input-port source)
           (close-output-port target)]
          [else 
           (write (mergesort-time nextval) target)
           (display "," target)
           (write (length nextval) target)
           (display "," target)
           (display "mergesort" target)
           (display "," target)
           (display "R" target)
           (display "," target)
           (display "Scheme" target)
           (newline target)
           (kernel source target)])))))