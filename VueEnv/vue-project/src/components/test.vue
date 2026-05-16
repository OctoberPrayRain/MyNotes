<template>
  <div>
    <h1>图书管理系统</h1>

    <!-- 搜索区域 -->
    <div style="margin-bottom: 15px;">
      <label>按出版社搜索：</label>
      <select v-model="tempSearchPublisher">
        <option value="">全部</option>
        <option v-for="pub in bookData.publishers" :key="pub">{{ pub }}</option>
      </select>
      <button @click="applySearch" style="margin-left: 10px;">搜索</button>
      <button @click="clearSearch" style="margin-left: 5px;">清除</button>
    </div>

    <!-- 添加或编辑表单 -->
    <div>
      <h2>{{ editing ? '编辑图书' : '添加新图书' }}</h2>
      <input v-model="form.title" placeholder="请输入书名" />
      <input v-model="form.author" placeholder="请输入作者" />

      <select v-model="form.publisher">
        <option value="" disabled selected>请选择出版社</option>
        <option v-for="pub in bookData.publishers" :key="pub">{{ pub }}</option>
      </select>

      <input v-model.number="form.stock" type="number" placeholder="库存数量" />

      <button @click="saveBook" :disabled="!form.title || !form.author || !form.publisher">
        {{ editing ? '更新' : '添加' }}
      </button>

      <button v-if="editing" @click="cancelEdit">取消</button>
    </div>

    <!-- 图书表格 -->
    <table v-if="displayBooks.length > 0" border="1" style="border-collapse: collapse; margin-top: 20px; width: 100%;">
      <tr>
        <th>序号</th>
        <th>书名</th>
        <th>作者</th>
        <th>出版社</th>
        <th>库存</th>
        <th>操作</th>
      </tr>
      <tr v-for="(book, index) in displayBooks" :key="book.id">
        <td>{{ index + 1 }}</td>
        <td>{{ book.title }}</td>
        <td>{{ book.author }}</td>
        <td>{{ book.publisher }}</td>
        <td :class="{ lowStock: book.stock < 10 }">{{ book.stock }}</td>
        <td>
          <button @click="editBook(book)">编辑</button>
          <button @click="deleteBook(book.id)">删除</button>
        </td>
      </tr>
    </table>

    <p v-else>暂无图书</p>

    <!-- 统计信息 -->
    <div v-show="displayBooks.length > 0">
      <p>当前显示 <strong>{{ displayBooks.length }}</strong> 本图书（共 {{ bookCount }} 本）</p>
    </div>
  </div>
</template>

<script setup>
import { ref, reactive, computed } from 'vue'

// 编辑状态
const editing = ref(false)
const editingId = ref(null)

// 搜索状态
const tempSearchPublisher = ref('') // 临时选择
const displayBooks = ref([]) // 实际显示的图书列表

// 图书数据
const bookData = reactive({
  publishers: ['人民邮电出版社', '清华大学出版社', '电子工业出版社'],
  books: [
    { id: 1, title: 'JavaScript高级程序设计', author: '尼古拉斯·泽卡斯', publisher: '人民邮电出版社', stock: 25 },
    { id: 2, title: 'Python编程：从入门到实践', author: '埃里克·马瑟斯', publisher: '人民邮电出版社', stock: 18 },
    { id: 3, title: '追风筝的人', author: '卡勒德·胡赛尼', publisher: '清华大学出版社', stock: 32 },
    { id: 4, title: '平凡的世界', author: '路遥', publisher: '电子工业出版社', stock: 45 },
    { id: 5, title: '人类简史：从动物到上帝', author: '尤瓦尔·赫拉利', publisher: '清华大学出版社', stock: 12 },
    { id: 6, title: '未来简史', author: '尤瓦尔·赫拉利', publisher: '清华大学出版社', stock: 8 },
    { id: 7, title: '时间简史', author: '史蒂芬·霍金', publisher: '电子工业出版社', stock: 15 },
    { id: 8, title: '解忧杂货店', author: '东野圭吾', publisher: '电子工业出版社', stock: 29 }
  ]
})

// 初始显示全部
displayBooks.value = bookData.books

// 表单数据
const form = reactive({
  title: '',
  author: '',
  publisher: '',
  stock: 0
})

// 计算总数
const bookCount = computed(() => bookData.books.length)

// 搜索
const applySearch = () => {
  if (!tempSearchPublisher.value) {
    displayBooks.value = bookData.books
  } else {
    displayBooks.value = bookData.books.filter(b => b.publisher === tempSearchPublisher.value)
  }
}

// 清除搜索
const clearSearch = () => {
  tempSearchPublisher.value = ''
  displayBooks.value = bookData.books
}

// 保存图书
const saveBook = () => {
  if (!form.title || !form.author || !form.publisher) return

  if (editing.value && editingId.value) {
    const book = bookData.books.find(b => b.id === editingId.value)
    if (book) {
      Object.assign(book, form)
    }
    editing.value = false
    editingId.value = null
  } else {
    const newId = Math.max(...bookData.books.map(b => b.id)) + 1
    bookData.books.push({ id: newId, ...form })
  }

  applySearch() // 保持当前搜索状态
  resetForm()
}

// 编辑图书
const editBook = (book) => {
  Object.assign(form, {...book})
  editing.value = true
  editingId.value = book.id
}

// 删除图书
const deleteBook = (id) => {
  if (confirm('确定要删除这本书吗？')) {
    const index = bookData.books.findIndex(b => b.id === id)
    if (index !== -1) {
      bookData.books.splice(index, 1)
    }
    applySearch()
  }
}

// 取消编辑
const cancelEdit = () => {
  editing.value = false
  editingId.value = null
  resetForm()
}

// 重置表单
const resetForm = () => {
  form.title = ''
  form.author = ''
  form.publisher = ''
  form.stock = 0
}
</script>

<style scoped>
td {
  text-align: center;
}
.lowStock {
  color: red;
  font-weight: bold;
}
</style>