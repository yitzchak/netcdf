(in-package #:blaze)

(defgeneric add (x y))

(defgeneric multiply (x y))

(defgeneric at (x i))

(defgeneric (setf at) (value x i))

(defgeneric nanp (x))

(defgeneric infinitep (x))

(defgeneric finitep (x))

(defgeneric defaultp (x))

(defgeneric uniformp (x))

(defgeneric zerop (x))

(defgeneric transpose (x))

(defgeneric norm (x))

(defgeneric sqr-norm (x))

#+(or)(defun blaze:+ (&rest args)
  (cond ((cdr args)
         (reduce #'add args))
        (args
         (car args))
        (t
         0)))

#+(or)(defun blaze:* (&rest args)
  (cond ((null args)
         1)
        ((null (cdr args))
         (car args))
        (t
         (reduce #'multiply args))))
    